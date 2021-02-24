/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptMgr.h"
#include "CreatureGroups.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "GridNotifiers.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "PassiveAI.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "Transport.h"
#include "halls_of_origination.h"

enum SunTouchedServant
{
    // Texts
    SAY_EMOTE_DISPERSE         = 0,

    // Spells
    SPELL_SEARING_FLAMES        = 74101,
    SPELL_DISPERSE_SERVANT      = 88097,
    SPELL_DISPERSE_SPRITE       = 88100,
    SPELL_FLAME_DISPERSION      = 76160,
    SPELL_PYROGENICS_SPRITE     = 76158,
    SPELL_PYROGENICS_SPRITELING = 76159,

    // Events
    EVENT_SEARING_FLAMES        = 1
};

struct npc_sun_touched_servant : public ScriptedAI
{
    npc_sun_touched_servant(Creature* creature) : ScriptedAI(creature), _dispersed(false) { }

    void JustAppeared() override
    {
        if (me->GetEntry() == NPC_SUN_TOUCHED_SERVANT)
            return;

        DoCastSelf(me->GetEntry() == NPC_SUN_TOUCHED_SPRITE ? SPELL_PYROGENICS_SPRITE : SPELL_PYROGENICS_SPRITELING);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_SEARING_FLAMES, 5s, 7s);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        ScriptedAI::EnterEvadeMode(why);
        _events.Reset();
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (me->GetEntry() == NPC_SUN_TOUCHED_SPRITELING)
            return;

        if (!_dispersed && me->HealthBelowPctDamaged(1, damage))
        {
            _dispersed = true;
            DoCastSelf(me->GetEntry() == NPC_SUN_TOUCHED_SERVANT ? SPELL_DISPERSE_SERVANT : SPELL_DISPERSE_SPRITE);
            Talk(SAY_EMOTE_DISPERSE);
        }

        if (damage >= me->GetHealth())
            damage = me->GetHealth() - 1;
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SEARING_FLAMES:
                    DoCastVictim(SPELL_SEARING_FLAMES);
                    _events.Repeat(8s, 14s);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
    bool _dispersed;
};

enum AggroStalker
{
    // Spells
    SPELL_SUBMERGE  = 76084,
    SPELL_EMERGE    = 75764
};

struct npc_hoo_aggro_stalker_base : public ScriptedAI
{
    npc_hoo_aggro_stalker_base(Creature* creature, uint8 summonGroupId) : ScriptedAI(creature), _summonGroupId(summonGroupId) { }

    void InitializeAI() override
    {
        // Trigger creatures are passive by default but we need an aggressive one here.
        me->SetReactState(REACT_AGGRESSIVE);
    }

    void JustAppeared() override
    {
        me->SummonCreatureGroup(_summonGroupId);
    }

    void AttackStart(Unit* /*who*/) override {  }

    void JustEngagedWith(Unit* who) override
    {
        for (ObjectGuid const& guid : _summonGUIDs)
        {
            if (Creature* summon = ObjectAccessor::GetCreature(*me, guid))
            {
                summon->EngageWithTarget(who);
                if (summon->HasAura(SPELL_SUBMERGE))
                {
                    summon->RemoveAurasDueToSpell(SPELL_SUBMERGE);
                    summon->CastSpell(summon, SPELL_EMERGE);
                }
            }
        }
    }

    void JustSummoned(Creature* summon) override
    {
        _summonGUIDs.insert(summon->GetGUID());
        summon->CastSpell(summon, SPELL_SUBMERGE, true); // The spell has a cast time but we need them submerged immediately
    }

    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
    {
        _summonGUIDs.erase(summon->GetGUID());

        // Group has been defeated, despawn aggro stalker.
        if (_summonGUIDs.empty())
            me->DespawnOrUnsummon();
    }

private:
    uint8 _summonGroupId;
    GuidSet _summonGUIDs;
};

struct npc_hoo_aggro_stalker_1 : public npc_hoo_aggro_stalker_base { npc_hoo_aggro_stalker_1(Creature* creature) : npc_hoo_aggro_stalker_base(creature, 0) { } };
struct npc_hoo_aggro_stalker_2 : public npc_hoo_aggro_stalker_base { npc_hoo_aggro_stalker_2(Creature* creature) : npc_hoo_aggro_stalker_base(creature, 1) { } };
struct npc_hoo_aggro_stalker_3 : public npc_hoo_aggro_stalker_base { npc_hoo_aggro_stalker_3(Creature* creature) : npc_hoo_aggro_stalker_base(creature, 2) { } };

// The Maker's Lift
enum ElevatorMisc
{
    GOSSIP_MENU_HOO_LIFT                    = 12646,
    GOSSIP_NPC_TEXT_CHOOSE_A_DESTINATION    = 17791,
    GOSSIP_OPTION_FIRST_FLOOR               = 0,
    GOSSIP_OPTION_HOO_LIFT_SECOND_FLOOR     = 1,
    GOSSIP_OPTION_HOO_LIFT_THIRD_FLOOR      = 2
};

// 207669 - The Maker's Lift Controller
struct go_hoo_the_makers_lift_controller : public GameObjectAI
{
    go_hoo_the_makers_lift_controller(GameObject* go) : GameObjectAI(go) { }

    bool GossipHello(Player* player) override
    {
        InstanceScript* instance = player->GetInstanceScript();
        if (!instance)
            return false;

        // Build menu.
        // First floor: Option available from start.
        AddGossipItemFor(player, GOSSIP_MENU_HOO_LIFT, GOSSIP_OPTION_FIRST_FLOOR, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 0);

        // Second floor: Anraphet must be defeated first.
        if (instance->GetBossState(DATA_ANRAPHET) == DONE || instance->GetBossState(DATA_EARTHRAGER_PTAH) == DONE)
            AddGossipItemFor(player, GOSSIP_MENU_HOO_LIFT, GOSSIP_OPTION_HOO_LIFT_SECOND_FLOOR, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

        // Third floor: Constructs of The Four Seats must be defeated first.
        if (instance->GetBossState(DATA_ISISET) == DONE && instance->GetBossState(DATA_AMMUNAE) == DONE &&
            instance->GetBossState(DATA_SETESH) == DONE && instance->GetBossState(DATA_RAJH) == DONE)
            AddGossipItemFor(player, GOSSIP_MENU_HOO_LIFT, GOSSIP_OPTION_HOO_LIFT_THIRD_FLOOR, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);

        SendGossipMenuFor(player, GOSSIP_NPC_TEXT_CHOOSE_A_DESTINATION, me->GetGUID());
        return true;
    }

    bool GossipSelect(Player* player, uint32 /*sender*/, uint32 action) override
    {
        ClearGossipMenuFor(player);
        player->PlayerTalkClass->SendCloseGossip();

        InstanceScript* instance = player->GetInstanceScript();
        if (!instance)
            return true;

        // Handle elevator: gossip item index => stopFrame (floor index).
        Transport* elevator = ObjectAccessor::GetTransportOnMap(*me, instance->GetGuidData(DATA_LIFT_OF_THE_MAKERS));
        if (!elevator)
            return true;

        if (action == 0 && elevator->GetGoState() >= GO_STATE_TRANSPORT_ACTIVE + 2)
            elevator->SetTransportState(GO_STATE_TRANSPORT_ACTIVE);
        else
            elevator->SetTransportState(GO_STATE_TRANSPORT_STOPPED, action);

        return true;
    }
};

class spell_hoo_flame_ring_visual : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.remove_if([](WorldObject const* target)->bool
        {
            Unit const* unit = target->ToUnit();
            return !unit || unit->GetEntry() != NPC_SUN_TOUCHED_SERVANT;
        });

        if (targets.empty())
            return;

        Trinity::Containers::RandomResize(targets, 1);
    }

    void HandleScriptEffect(SpellEffIndex effIndex)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetHitUnit(), GetSpellInfo()->Effects[effIndex].BasePoints, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_hoo_flame_ring_visual::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
        OnEffectHitTarget.Register(&spell_hoo_flame_ring_visual::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_hoo_disperse : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FLAME_DISPERSION });
    }

    void HandleDeath(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->CastSpell(target, SPELL_FLAME_DISPERSION);
        target->KillSelf(); // There is no suicide spell being shown in sniffs
    }

    void Register() override
    {
        AfterEffectRemove.Register(&spell_hoo_disperse::HandleDeath, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_hoo_submerge : public AuraScript
{
    void HandleFlagsAfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        if (target->IsCreature())
            target->ToCreature()->SetReactState(REACT_PASSIVE);
    }

    void HandleFlagsAfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        GetTarget()->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        if (target->IsCreature())
            target->ToCreature()->SetReactState(REACT_AGGRESSIVE);
    }

    void Register() override
    {
        AfterEffectApply.Register(&spell_hoo_submerge::HandleFlagsAfterApply, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove.Register(&spell_hoo_submerge::HandleFlagsAfterRemove, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_halls_of_origination()
{
    RegisterHallsOfOriginationCreatureAI(npc_sun_touched_servant);
    RegisterHallsOfOriginationCreatureAI(npc_hoo_aggro_stalker_1);
    RegisterHallsOfOriginationCreatureAI(npc_hoo_aggro_stalker_2);
    RegisterHallsOfOriginationCreatureAI(npc_hoo_aggro_stalker_3);
    RegisterGameObjectAI(go_hoo_the_makers_lift_controller);
    RegisterSpellScript(spell_hoo_flame_ring_visual);
    RegisterSpellScript(spell_hoo_disperse);
    RegisterSpellScript(spell_hoo_submerge);
}
