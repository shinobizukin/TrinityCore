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
#include "CombatAI.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "GameEventMgr.h"
#include "Log.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "Spell.h"
#include "SpellInfo.h"
#include "SpellDefines.h"
#include "TemporarySummon.h"
#include "Vehicle.h"
#include "Unit.h"

enum KezanEnumerate
{
    SPELL_INVISIBILITY_DETECTION_4 = 90161,
    SPELL_INVISIBILITY_DETECTION_5 = 94566,
    QUEST_NECESSARY_ROUGHNESS = 24502
};

enum KezanEvents
{
    EVENT_PLAY_SOUND1,
    EVENT_START_PLAY_GAME,
    EVENT_PERIODIC_CHEERING
};

enum CitizenEmotes {
    E1      = 1,
    E4      = 4,
    E5      = 5,
    E6      = 6,
    E11     = 11,
    E14     = 14,
    E15     = 15,
    E25     = 25,
    E92     = 92,
    E94     = 94,
    E274    = 274
};

class npc_bilgewater_buccaneer_necessary_roughness : public CreatureScript
{
public:
    npc_bilgewater_buccaneer_necessary_roughness() : CreatureScript("npc_bilgewater_buccaneer_necessary_roughness") { }

    enum enum_spells
    {
        SPELL_SUMMON_STEAMWHEEDLE_SHARK = 69971,
        SPELL_DESPAWN_SUMMONED_STEAMWHEEDLE_SHARKS = 69987
    };

    enum enum_npcs
    {
        NPC_STEAMWHEEDLE_SHARK = 37114
    };

    struct npc_bilgewater_buccaneer_necessary_roughness_ai : public VehicleAI
    {

        std::list<ObjectGuid> steamwheedleSharks;

        npc_bilgewater_buccaneer_necessary_roughness_ai(Creature* creature) : VehicleAI(creature) { }

        void Reset() override
        {
            TC_LOG_TRACE("scripts","Enter Reset for npc_bilgewater_buccaneer_necessary_roughness_ai");
            if (Player* player = me->GetOwner()->ToPlayer()) 
            {
                PlayerExit(player);
            }
            me->AddAura(SPELL_INVISIBILITY_DETECTION_5, me);
            me->SetOrientation(3.19f);
        }

        void PassengerBoarded(Unit* passenger, int8 /*seat*/, bool apply) override
        {
            TC_LOG_TRACE("scripts","Enter PassengerBoarded for npc_bilgewater_buccaneer_necessary_roughness_ai");
            uint8 isApplied = 0;
            if (apply) {
                isApplied = 1;    
            }
            if (apply) 
            {
                if (Player* player = passenger->ToPlayer())
                {
                    playerGUID = player->GetGUID();
                    player->RemoveAura(SPELL_INVISIBILITY_DETECTION_4);
                    TC_LOG_TRACE("scripts","npc_bilgewater_buccaneer_necessary_roughness_ai remove SPELL_INVISIBILITY_DETECTION_4");
                    player->AddAura(SPELL_INVISIBILITY_DETECTION_5, player);
                    me->AddAura(SPELL_INVISIBILITY_DETECTION_5, me);
                    TC_LOG_TRACE("scripts","npc_bilgewater_buccaneer_necessary_roughness_ai add SPELL_INVISIBILITY_DETECTION_5");
                    if (player->GetQuestStatus(QUEST_NECESSARY_ROUGHNESS) == QUEST_STATUS_INCOMPLETE)
                    {
                        TC_LOG_TRACE("scripts","npc_bilgewater_buccaneer_necessary_roughness_ai schedule events");
                        _events.ScheduleEvent(EVENT_PLAY_SOUND1, 1000);
                        _events.ScheduleEvent(EVENT_START_PLAY_GAME, 4000);
                        _events.ScheduleEvent(EVENT_PERIODIC_CHEERING, 250);
                    }
                }
            }
            else 
            {
                if (Player* player = passenger->ToPlayer())
                {
                    TC_LOG_TRACE("scripts","Enter PassengerBoarded for npc_bilgewater_buccaneer_necessary_roughness_ai, !apply");
                    PlayerExit(player);
                }
            }
        }

        void OnSpellCastFinished(SpellInfo const* spell, SpellFinishReason /*reason*/) override
        {  
            TC_LOG_TRACE("scripts","Enter OnSpellCastFinished for npc_bilgewater_buccaneer_necessary_roughness_ai with spell %i", spell->Id);
            // Creature* shark = me->FindNearestCreature(NPC_STEAMWHEEDLE_SHARK, 100.0f, true);
            Player* player = me->GetOwner()->ToPlayer();
            if (player) {
                auto sharkGuid = steamwheedleSharks.back();
                if (Creature* shark = ObjectAccessor::GetCreature(*me, sharkGuid)) {
                    TC_LOG_TRACE("scripts","npc_bilgewater_buccaneer_necessary_roughness_ai cast spell");
                    CastSpellExtraArgs args(TRIGGERED_IGNORE_CASTER_MOUNTED_OR_ON_VEHICLE);
                    steamwheedleSharks.remove(sharkGuid);
                    player->CastSpell(shark, spell->Id, args);
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);
            VehicleAI::UpdateAI(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_PLAY_SOUND1:
                {
                    TC_LOG_TRACE("scripts","npc_bilgewater_buccaneer_necessary_roughness_ai EVENT_PLAY_SOUND1");
                    if (Player* player = ObjectAccessor::GetPlayer(*me, playerGUID))
                    {
                        player->PlayDirectSound(17466, player);
                        _events.ScheduleEvent(EVENT_PLAY_SOUND1, 1000);
                    }
                    break;
                }
                case EVENT_START_PLAY_GAME:
                {
                    TC_LOG_TRACE("scripts","npc_bilgewater_buccaneer_necessary_roughness_ai EVENT_START_PLAY_GAME");
                    StartPlayGame();
                    break;
                }
                case EVENT_PERIODIC_CHEERING:
                {
                    TC_LOG_TRACE("scripts","npc_bilgewater_buccaneer_necessary_roughness_ai EVENT_PERIODIC_CHEERING");
                    for (uint32 i = 0; i < urand(3, 10); i++)
                        if (Creature* npc = GetRandomObserver())
                            npc->HandleEmoteCommand(GetRandomEmote());

                    _events.ScheduleEvent(EVENT_PERIODIC_CHEERING, 500);
                    break;
                }
                }
            }

            if (!UpdateVictim())
                return;
            else
                DoMeleeAttackIfReady();
        }

        void StartPlayGame()
        {
            TC_LOG_TRACE("scripts","npc_bilgewater_buccaneer_necessary_roughness_ai StartPlayGame");
            const int casts = 8;
            float targetsArray[casts][3] = { 
                { -8291.62f, 1479.97f, 43.8908f }, 
                { -8285.75f, 1484.46f, 42.9395f }, 
                { -8291.08f, 1487.72f, 43.8463f }, 
                { -8288.04f, 1477.49f, 43.3046f }, 
                { -8288.33f, 1490.41f, 43.4756f }, 
                { -8295.10f, 1484.91f, 44.3231f }, 
                { -8294.66f, 1474.68f, 44.2946f }, 
                { -8294.61f, 1493.67f, 44.6239f }
            };
            Player* player = me->GetOwner()->ToPlayer();
            Creature* myCreature = me->ToCreature();
            Creature* buccaneer48526 = me->FindNearestCreature(48526, 50.0f);

            TC_LOG_TRACE("scripts","npc_bilgewater_buccaneer_necessary_roughness_ai targetsArray initialized");
            for (int i = 0; i < casts; i++) 
            {
                SpellCastTargets targets;
                Position p(targetsArray[i][0], targetsArray[i][1], targetsArray[i][2], 0);
                WorldLocation wl(me->GetMapId(), p);
                CastSpellExtraArgs args(TRIGGERED_IGNORE_CASTER_MOUNTED_OR_ON_VEHICLE + TRIGGERED_FULL_MASK);
                targets.SetDst(wl);
                if (i == 0) {
                    TC_LOG_TRACE("scripts","npc_bilgewater_buccaneer_necessary_roughness_ai SPELL_SUMMON_STEAMWHEEDLE_SHARK %i",SPELL_SUMMON_STEAMWHEEDLE_SHARK + i);
                    //player->CastSpell(p, SPELL_SUMMON_STEAMWHEEDLE_SHARK + i, args);
                    TempSummon* summon = player->SummonCreature(NPC_STEAMWHEEDLE_SHARK, p, TEMPSUMMON_MANUAL_DESPAWN, 0U, 0U, true);
                    steamwheedleSharks.push_back(summon->GetGUID());
                }
                else {
                    TC_LOG_TRACE("scripts","npc_bilgewater_buccaneer_necessary_roughness_ai SPELL_SUMMON_STEAMWHEEDLE_SHARK %i",SPELL_SUMMON_STEAMWHEEDLE_SHARK + i + 4);
                    //player->CastSpell(p, SPELL_SUMMON_STEAMWHEEDLE_SHARK + i + 4, args);
                    TempSummon* summon = player->SummonCreature(NPC_STEAMWHEEDLE_SHARK, p, TEMPSUMMON_MANUAL_DESPAWN, 0U, 0U, true);
                    steamwheedleSharks.push_back(summon->GetGUID());
                }

            }
        }

        void PlayerExit(Player* player) 
        {
            TC_LOG_TRACE("scripts","npc_bilgewater_buccaneer_necessary_roughness_ai player exit");
            CastSpellExtraArgs args(TRIGGERED_IGNORE_CASTER_MOUNTED_OR_ON_VEHICLE);
            player->CastSpell(me, SPELL_DESPAWN_SUMMONED_STEAMWHEEDLE_SHARKS, args);
            player->RemoveAura(SPELL_INVISIBILITY_DETECTION_5);
            player->AddAura(SPELL_INVISIBILITY_DETECTION_4, player);
            for (auto guid : steamwheedleSharks)
                if (Creature* shark = ObjectAccessor::GetCreature(*me, guid)) {
                    TC_LOG_TRACE("scripts","npc_bilgewater_buccaneer_necessary_roughness_ai despawn shark");
                    shark->DespawnOrUnsummon(1);
                }
            _events.Reset();
            steamwheedleSharks.clear();
        }

        // void LoadObserver()
        // {
        //     Creature* cr = me->FindNearestCreature(35063, 50.0f);
        //     zList.push_back(cr->GetGUID());
        // }

        uint32 GetRandomEmote()
        {
            return RAND(E1, E4, E5, E6, E11, E14, E15, E25, E92, E94, E274);
        }

        Creature* GetRandomObserver()
        {
            // if (zList.size() == 0)
            //     LoadObserver();
            // else
            // {
            //     uint32 rol2 = urand(0, zList.size() - 1);
            //     std::list<uint64>::iterator itr = zList.begin();
            //     std::advance(itr, rol2);
            //     return ObjectAccessor::GetCreature(*me, *itr);
            // }
            // return nullptr;
            return me->FindNearestCreature(35063, 50.0f);
        }

    private:
        EventMap _events;
        ObjectGuid playerGUID;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {   
        return new npc_bilgewater_buccaneer_necessary_roughness_ai(creature);
    }
};

class npc_steamwheedle_shark_necessary_roughness : public CreatureScript
{
public:
    npc_steamwheedle_shark_necessary_roughness() : CreatureScript("npc_steamwheedle_shark_necessary_roughness") { }

    enum npcs {
        NPC_BILGEWATER_BUCCANEER = 37179,
        NPC_STEAMWHEEDLE_SHARK = 37114,
        SPELL_THROW_FOOTBOMB = 69993
    };

    enum events {
        EVENT_WE_ARE_KILLED = 1
    };

    enum spells {
        SPELL_PERMANENT_FEIGN_DEATH = 29266
    };

    enum sharkEnums {
        PLAYER_GUID
    };

    struct npc_steamwheedle_shark_necessary_roughness_ai : public ScriptedAI
    {
        npc_steamwheedle_shark_necessary_roughness_ai(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            _player = nullptr;
            playerGUID = ObjectGuid();
            buccaneerGUID = 0;
        }

        void IsSummonedBy(Unit* summoner) override 
        { 
            TC_LOG_TRACE("scripts","Enter IsSummonedBy for npc_steamwheedle_shark_necessary_roughness_ai");
            if (Player* player = summoner->ToPlayer())
                if (Vehicle* npc = player->GetVehicle()) {
                    _player = player;
                    me->AI()->SetGUID(player->GetOwnerGUID(), PLAYER_GUID);
                    if (npc->GetCreatureEntry() == NPC_BILGEWATER_BUCCANEER)
                        buccaneerGUID = npc->GetCreatureEntry();
                }
        }

        void SpellHit(Unit* caster, SpellInfo const* spell) override 
        { 
            TC_LOG_TRACE("scripts","Enter SpellHit for npc_steamwheedle_shark_necessary_roughness_ai with spell %i", spell->Id);
            if (spell->Id == SPELL_THROW_FOOTBOMB) {
                me->GetMotionMaster()->Clear();
                me->GetMotionMaster()->MoveIdle();
                _events.ScheduleEvent(EVENT_WE_ARE_KILLED, 10);
            }
        }

        void SetGUID(ObjectGuid const& guid, int32 id) override
        {
            TC_LOG_TRACE("scripts","Enter SetGUID for playerGuid %u npc_steamwheedle_shark_necessary_roughness_ai", guid.GetEntry());
            switch (id)
            {
            case PLAYER_GUID:
                playerGUID = guid;
                break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_WE_ARE_KILLED:
                {
                    TC_LOG_TRACE("scripts","EVENT_WE_ARE_KILLED playerGUID %u npc_steamwheedle_shark_necessary_roughness_ai", playerGUID.GetEntry());
                    if (/*Player* player = ObjectAccessor::GetPlayer(*me, playerGUID)*/_player)
                    {
                        TC_LOG_TRACE("scripts","Awarding qquest credit for npc_steamwheedle_shark_necessary_roughness_ai");
                        _player->Kill(me);
                        me->AddAura(SPELL_PERMANENT_FEIGN_DEATH, me);
                        _player->KilledMonsterCredit(NPC_STEAMWHEEDLE_SHARK);
                    }
                    break;
                }
                }
            }

            if (!UpdateVictim())
                return;
            else
                DoMeleeAttackIfReady();
        }
    private:
        EventMap _events;
        ObjectGuid playerGUID;
        Player* _player;
        uint64 buccaneerGUID;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_steamwheedle_shark_necessary_roughness_ai(creature);
    }
};

class npc_bilgewater_buccaneer_fourth_and_goal : public CreatureScript
{
public:
    npc_bilgewater_buccaneer_fourth_and_goal() : CreatureScript("npc_bilgewater_buccaneer_fourth_and_goal") { }

    struct npc_bilgewater_buccaneer_fourth_and_goal_ai : public VehicleAI
    {
        npc_bilgewater_buccaneer_fourth_and_goal_ai(Creature* creature) : VehicleAI(creature) { }

        enum spells {
            SPELL_KICK_FOOTBOMB = 70051
        };
        enum credit {
            FOURTH_AND_GOAL_TARGET = 37203
        };

        void OnSpellCastFinished(SpellInfo const* spell, SpellFinishReason /*reason*/) override
        {  
            TC_LOG_TRACE("scripts","Enter OnSpellCastFinished for npc_bilgewater_fourth_and_goal_ai with spell %i", spell->Id);
            // Creature* shark = me->FindNearestCreature(NPC_STEAMWHEEDLE_SHARK, 100.0f, true);
            if (spell->Id == SPELL_KICK_FOOTBOMB) {
                Player* player = me->GetOwner()->ToPlayer();
                if (player) {
                    player->KilledMonsterCredit(FOURTH_AND_GOAL_TARGET);
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_bilgewater_buccaneer_fourth_and_goal_ai(creature);
    }
};

void AddSC_kezan()
{
    new npc_bilgewater_buccaneer_necessary_roughness();
    new npc_steamwheedle_shark_necessary_roughness();
    new npc_bilgewater_buccaneer_fourth_and_goal();
}
