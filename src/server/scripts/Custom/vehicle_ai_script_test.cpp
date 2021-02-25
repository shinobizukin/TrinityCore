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
#include "Log.h"
#include "Player.h"
#include "QuestDef.h"
#include "Vehicle.h"
#include "Unit.h"

class npc_test_vehicle : public CreatureScript
{
public:
    npc_test_vehicle() : CreatureScript("npc_test_vehicle") { }

    struct npc_test_vehicle_ai : public VehicleAI
    {
        npc_test_vehicle_ai(Creature* creature) : VehicleAI(creature) { }

        // VehicleAI Methods
        void MoveInLineOfSight(Unit*) override 
        {
            TC_LOG_DEBUG("scripts","Enter MoveInLineOfSight for npc_test_vehicle_ai");
        }
        void AttackStart(Unit*) override 
        { 
            TC_LOG_DEBUG("scripts","Enter AttackStart for npc_test_vehicle_ai");
        }
        void OnCharmed(bool apply) override 
        {
            TC_LOG_DEBUG("scripts","Enter OnCharmed for npc_test_vehicle_ai");
        }

        // CreatureAI
        void JustStartedThreateningMe(Unit* who) override
        {
            TC_LOG_DEBUG("scripts","Enter JustStartedThreateningMe for npc_test_vehicle_ai"); 
            if (!IsEngaged()) EngagementStart(who); 
        }

        // Called for reaction when initially engaged
        void JustEngagedWith(Unit* /*who*/) override
        { 
            TC_LOG_DEBUG("scripts","Enter JustEngagedWith for npc_test_vehicle_ai"); 
        }

        // Called when the creature is killed
        void JustDied(Unit* /*killer*/) override
        { 
            TC_LOG_DEBUG("scripts","Enter JustDied for npc_test_vehicle_ai"); 
        }

        // Called when the creature kills a unit
        void KilledUnit(Unit* /*victim*/) override
        { 
            TC_LOG_DEBUG("scripts","Enter KilledUnit for npc_test_vehicle_ai");
        }

        // Called when the creature summon successfully other creature
        void JustSummoned(Creature* /*summon*/) override
        { 
            TC_LOG_DEBUG("scripts","Enter JustSummoned for npc_test_vehicle_ai");
        }

        void IsSummonedBy(Unit* summoner) override
        {
            TC_LOG_DEBUG("scripts","Enter IsSummonedBy for npc_test_vehicle_ai");
        }

        void SummonedCreatureDespawn(Creature* /*summon*/) override
        { 
            TC_LOG_DEBUG("scripts","Enter SummonedCreatureDespawn for npc_test_vehicle_ai");
        }
        void SummonedCreatureDies(Creature* /*summon*/, Unit* /*killer*/) override
        { 
            TC_LOG_DEBUG("scripts","Enter SummonedCreatureDies for npc_test_vehicle_ai");
        }

        // Called when the creature successfully summons a gameobject
        void JustSummonedGameobject(GameObject* /*gameobject*/) override
        { 
            TC_LOG_DEBUG("scripts","Enter JustSummonedGameobject for npc_test_vehicle_ai");
        }
        void SummonedGameobjectDespawn(GameObject* /*gameobject*/) override
        { 
            TC_LOG_DEBUG("scripts","Enter SummonedGameobjectDespawn for npc_test_vehicle_ai");
        }

        // Called when the creature successfully registers a dynamicobject
        void JustRegisteredDynObject(DynamicObject* /*dynObject*/) override
        { 
            TC_LOG_DEBUG("scripts","Enter JustRegisteredDynObject for npc_test_vehicle_ai");
        }
        void JustUnregisteredDynObject(DynamicObject* /*dynObject*/) override
        { 
            TC_LOG_DEBUG("scripts","Enter JustUnregisteredDynObject for npc_test_vehicle_ai");
        }

        // Called when hit by a spell
        void SpellHit(Unit* /*caster*/, SpellInfo const* /*spell*/) override
        { 
            TC_LOG_DEBUG("scripts","Enter SpellHit for npc_test_vehicle_ai");
        }

        // Called when spell hits a target
        void SpellHitTarget(Unit* /*target*/, SpellInfo const* /*spell*/) override
        { 
            TC_LOG_DEBUG("scripts","Enter SpellHitTarget for npc_test_vehicle_ai");
        }

        // Should return true if the NPC is currently being escorted
        bool IsEscorted() const override
        {
            TC_LOG_DEBUG("scripts","Enter IsEscorted for npc_test_vehicle_ai"); 
            return false; 
        }

        void JustAppeared() override
        {
            TC_LOG_DEBUG("scripts","Enter JustAppeared for npc_test_vehicle_ai");
        }

        // Called at waypoint reached or point movement finished
        void MovementInform(uint32 /*type*/, uint32 /*id*/) override
        { 
            TC_LOG_DEBUG("scripts","Enter MovementInform for npc_test_vehicle_ai");
        }

        void OnSpellCastFinished(SpellInfo const* /*spell*/, SpellFinishReason /*reason*/) override
        {  
            TC_LOG_DEBUG("scripts","Enter OnSpellCastFinished for npc_test_vehicle_ai");
        }

        // Called at reaching home after evade
        void JustReachedHome() override
        { 
            TC_LOG_DEBUG("scripts","Enter JustReachedHome for npc_test_vehicle_ai");
        }

        // Called at text emote receive from player
        void ReceiveEmote(Player* /*player*/, uint32 /*emoteId*/) override
        {
            TC_LOG_DEBUG("scripts","Enter ReceiveEmote for npc_test_vehicle_ai");
        }

        // Called when owner takes damage
        void OwnerAttackedBy(Unit* attacker) override
        {
            TC_LOG_DEBUG("scripts","Enter OwnerAttackedBy for npc_test_vehicle_ai");
        }

        // Called when owner attacks something
        void OwnerAttacked(Unit* target) override
        { 
            TC_LOG_DEBUG("scripts","Enter OwnerAttacked for npc_test_vehicle_ai");
        }

        // called when the corpse of this creature gets removed
        void CorpseRemoved(uint32& /*respawnDelay*/) override
        { 
            TC_LOG_DEBUG("scripts","Enter CorpseRemoved for npc_test_vehicle_ai");
        }

        /// == Gossip system ================================

        // Called when the dialog status between a player and the creature is requested.
        Optional<QuestGiverStatus> GetDialogStatus(Player* /*player*/) override
        {
            TC_LOG_DEBUG("scripts","Enter GetDialogStatus for npc_test_vehicle_ai"); 
            return DIALOG_STATUS_NONE; 
        }

        // Called when a player opens a gossip dialog with the creature.
        bool GossipHello(Player* /*player*/) override
        {
            TC_LOG_DEBUG("scripts","Enter GossipHello for npc_test_vehicle_ai"); 
            return false; 
        }

        // Called when a player selects a gossip item in the creature's gossip menu.
        bool GossipSelect(Player* /*player*/, uint32 /*menuId*/, uint32 /*gossipListId*/) override
        { 
            TC_LOG_DEBUG("scripts","Enter GossipSelect for npc_test_vehicle_ai");
            return false; 
        }

        // Called when a player selects a gossip with a code in the creature's gossip menu.
        bool GossipSelectCode(Player* /*player*/, uint32 /*menuId*/, uint32 /*gossipListId*/, char const* /*code*/) override
        { 
            TC_LOG_DEBUG("scripts","Enter GossipSelectCode for npc_test_vehicle_ai");
            return false; 
        }

        // Called when a player accepts a quest from the creature.
        void QuestAccept(Player* /*player*/, Quest const* /*quest*/) override
        { 
            TC_LOG_DEBUG("scripts","Enter QuestAccept for npc_test_vehicle_ai");
        }

        // Called when a player completes a quest and is rewarded, opt is the selected item's index or 0
        void QuestReward(Player* /*player*/, Quest const* /*quest*/, uint32 /*opt*/) override
        { 
            TC_LOG_DEBUG("scripts","Enter QuestReward for npc_test_vehicle_ai");
        }

        /// == Waypoints system =============================

        void WaypointPathStarted(uint32 /*pathId*/) override
        { 
            TC_LOG_DEBUG("scripts","Enter WaypointPathStarted for npc_test_vehicle_ai");
        }
        void WaypointStarted(uint32 /*nodeId*/, uint32 /*pathId*/) override
        { 
            TC_LOG_DEBUG("scripts","Enter WaypointStarted for npc_test_vehicle_ai");
        }
        void WaypointReached(uint32 /*nodeId*/, uint32 /*pathId*/) override
        { 
            TC_LOG_DEBUG("scripts","Enter WaypointReached for npc_test_vehicle_ai");
        }
        void WaypointPathEnded(uint32 /*nodeId*/, uint32 /*pathId*/) override
        { 
            TC_LOG_DEBUG("scripts","Enter WaypointPathEnded for npc_test_vehicle_ai");
        }

        void PassengerBoarded(Unit* passenger, int8 /*seat*/, bool apply) override
        {
            TC_LOG_DEBUG("scripts","Enter PassengerBoarded for npc_test_vehicle_ai");
        }

        void OnSpellClick(Unit* /*clicker*/, bool& /*result*/) override
        { 
            TC_LOG_DEBUG("scripts","Enter OnSpellClick for npc_test_vehicle_ai");
        }

        // Unit AI
        bool CanAIAttack(Unit const* /*target*/) const override
        {
            TC_LOG_DEBUG("scripts","Enter CanAIAttack for npc_test_vehicle_ai");
            return true; 
        }

        void InitializeAI() override
        {
            TC_LOG_DEBUG("scripts","Enter InitializeAI for npc_test_vehicle_ai");
        }

        void Reset() override
        {
            TC_LOG_DEBUG("scripts","Enter Reset for npc_test_vehicle_ai");
        }

        // Pass parameters between AI
        void DoAction(int32 /*param*/) override
        {
            TC_LOG_DEBUG("scripts","Enter DoAction for npc_test_vehicle_ai");
        }
        uint32 GetData(uint32 /*id = 0*/) const override
        {
            TC_LOG_DEBUG("scripts","Enter GetData for npc_test_vehicle_ai");
            return 0; 
        }
        void SetData(uint32 /*id*/, uint32 /*value*/) override
        {
            TC_LOG_DEBUG("scripts","Enter SetData for npc_test_vehicle_ai");
        }
        void SetGUID(ObjectGuid const& /*guid*/, int32 /*id*/ = 0) override
        {
            TC_LOG_DEBUG("scripts","Enter SetGUID for npc_test_vehicle_ai");
        }
        ObjectGuid GetGUID(int32 /*id*/ = 0) const override
        {
            TC_LOG_DEBUG("scripts","Enter GetGUID for npc_test_vehicle_ai");
            return ObjectGuid::Empty;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {   
        TC_LOG_DEBUG("scripts", "GetAI npc_test_vehicle_ai");
        return new npc_test_vehicle_ai(creature);
    }
};

void AddSC_vehicle_ai_test_script()
{
    TC_LOG_DEBUG("scripts", "AddSC_vehicle_ai_test_script script npc_test");
    new npc_test_vehicle();
}
