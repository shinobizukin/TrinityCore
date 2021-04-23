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
#include "GameObject.h"
#include "GameObjectAI.h"
#include "Log.h"
#include "Player.h"
#include "QuestDef.h"
#include "Unit.h"

class npc_test_gameobject : public GameObjectScript
{
public:
    npc_test_gameobject() : GameObjectScript("npc_test_gameobject") { }

    struct npc_test_gameobject_ai : public GameObjectAI
    {
        npc_test_gameobject_ai(GameObject* go) : GameObjectAI(go) { }

        void UpdateAI(uint32 diff) override
        {
            TC_LOG_DEBUG("scripts","Enter UpdateAI for npc_test_gameobject_ai diff: %u",diff);
        }

        void InitializeAI() override
        {
            TC_LOG_DEBUG("scripts","Enter InitializeAI for npc_test_gameobject_ai");
            Reset(); 
        }

        void Reset() override
        {
            TC_LOG_DEBUG("scripts","Enter Reset for npc_test_gameobject_ai");
        }

        void JustAppeared() override
        {
            TC_LOG_DEBUG("scripts","Enter JustAppeared for npc_test_gameobject_ai");
        }

        // Pass parameters between AI
        void DoAction(int32 param = 0) override
        {
            TC_LOG_DEBUG("scripts","Enter DoAction for npc_test_gameobject_ai param: %i",param);
        }
        void SetGUID(ObjectGuid const& /*guid*/, int32 id = 0) override
        {
            TC_LOG_DEBUG("scripts","Enter SetGUID for npc_test_gameobject_ai id: %i",id);
        }

        // Called when a player selects a gossip item in the gameobject's gossip menu.
        bool GossipSelect(Player* /*player*/, uint32 menuId, uint32 gossipListId) override
        {
            TC_LOG_DEBUG("scripts","Enter GossipSelect for npc_test_gameobject_ai menuId: %u, gossipListId: %u",menuId,gossipListId); 
            return false;
        }

        // Called when a player selects a gossip with a code in the gameobject's gossip menu.
        bool GossipSelectCode(Player* /*player*/, uint32 menuId, uint32 gossipListId, char const* code) override 
        {
            TC_LOG_DEBUG("scripts","Enter GossipSelectCode for npc_test_gameobject_ai menuId: %u, gossipListId: %u, code: %c",menuId,gossipListId,code);
            return false; 
        }

        // Called when a player accepts a quest from the gameobject.
        void QuestAccept(Player* /*player*/, Quest const* /*quest*/) override
        {
            TC_LOG_DEBUG("scripts","Enter QuestAccept for npc_test_gameobject_ai");
        }

        // Called when a player completes a quest and is rewarded, opt is the selected item's index or 0
        void QuestReward(Player* /*player*/, Quest const* /*quest*/, uint32 opt) override
        {
            TC_LOG_DEBUG("scripts","Enter QuestReward for npc_test_gameobject_ai opt: %u",opt);
        }

        // Called when a Player clicks a GameObject, before GossipHello
        // prevents achievement tracking if returning true
        bool OnReportUse(Player* /*player*/) override 
        {
            TC_LOG_DEBUG("scripts","Enter OnReportUse for npc_test_gameobject_ai"); 
            return false; 
        }

        void Destroyed(Player* /*player*/, uint32 eventId) override
        {
            TC_LOG_DEBUG("scripts","Enter Destroyed for npc_test_gameobject_ai eventId: %u",eventId);
        }

        void Damaged(Player* /*player*/, uint32 eventId) override
        {
            TC_LOG_DEBUG("scripts","Enter Damaged for npc_test_gameobject_ai eventId: %u",eventId);
        }

        uint32 GetData(uint32 id) const override
        { 
            TC_LOG_DEBUG("scripts","Enter GetData for npc_test_gameobject_ai id: %u",id);
            return 0; 
        }
        void SetData64(uint32 id, uint64 value) override
        {
            TC_LOG_DEBUG("scripts","Enter SetData64 for npc_test_gameobject_ai id: %u, value: %u",id,value);
        }
        uint64 GetData64(uint32 id) const override 
        {
            TC_LOG_DEBUG("scripts","Enter GetData64 for npc_test_gameobject_ai id: %u",id);
            return 0; 
        }
        void SetData(uint32 id, uint32 value) override
        {
            TC_LOG_DEBUG("scripts","Enter SetData for npc_test_gameobject_ai id: %u, value: %u",id,value);
        }

        void OnGameEvent(bool /*start*/, uint16 eventId) override
        {
            TC_LOG_DEBUG("scripts","Enter OnGameEvent for npc_test_gameobject_ai eventId: %u",eventId);
        }
        void OnLootStateChanged(uint32 state, Unit* /*unit*/) override
        {
            TC_LOG_DEBUG("scripts","Enter OnLootStateChanged for npc_test_gameobject_ai state: %u",state);
        }
        void OnStateChanged(uint32 state) override
        {
            TC_LOG_DEBUG("scripts","Enter OnStateChanged for npc_test_gameobject_ai state: %u",state);
        }
        void EventInform(uint32 eventId) override
        {
            TC_LOG_DEBUG("scripts","Enter EventInform for npc_test_gameobject_ai eventId: %u",eventId);
        }
        void SpellHit(Unit* /*unit*/, SpellInfo const* /*spellInfo*/) override
        {
            TC_LOG_DEBUG("scripts","Enter SpellHit for npc_test_gameobject_ai");
        }
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {   
        TC_LOG_DEBUG("scripts", "GetAI npc_test_gameobject_ai");
        return new npc_test_gameobject_ai(go);
    }
};

void AddSC_gameobject_ai_test_script()
{
    TC_LOG_DEBUG("scripts", "AddSC_gameobject_ai_test_script script npc_test");
    new npc_test_gameobject();
}
