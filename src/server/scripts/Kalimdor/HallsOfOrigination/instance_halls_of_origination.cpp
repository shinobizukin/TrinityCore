/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "halls_of_origination.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "CreatureGroups.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "World.h"

DoorData const doorData[] =
{
    { GO_DOODAD_ULDUM_DOOR_14,         DATA_TEMPLE_GUARDIAN_ANHUUR, DOOR_TYPE_ROOM    },
    { GO_DOODAD_ULDUM_DOOR_15,         DATA_TEMPLE_GUARDIAN_ANHUUR, DOOR_TYPE_PASSAGE },
    { GO_ANHUURS_BRIDGE,               DATA_TEMPLE_GUARDIAN_ANHUUR, DOOR_TYPE_PASSAGE },
    { GO_DOODAD_ULDUM_ELEVATOR_COL01,  DATA_TEMPLE_GUARDIAN_ANHUUR, DOOR_TYPE_PASSAGE },
    { GO_LIFT_GLASS_STAR,              DATA_ANRAPHET,               DOOR_TYPE_PASSAGE },
    { GO_LIFT_GLASS_STAR_2,            DATA_ANRAPHET,               DOOR_TYPE_PASSAGE },
    { 0,                               0,                           DOOR_TYPE_ROOM    }
};

/*BossBoundaryData const boundaries =
{
};*/

ObjectData const creatureData[] =
{
    { BOSS_TEMPLE_GUARDIAN_ANHUUR,      DATA_TEMPLE_GUARDIAN_ANHUUR },
    { BOSS_EARTHRAGER_PTAH,             DATA_EARTHRAGER_PTAH        },
    { NPC_BRANN_BRONZEBEARD_0,          DATA_BRANN_0                },
    { NPC_FIRE_WARDEN,                  DATA_FIRE_WARDEN            },
    { NPC_EARTH_WARDEN,                 DATA_EARTH_WARDEN           },
    { NPC_WATER_WARDEN,                 DATA_WATER_WARDEN           },
    { NPC_AIR_WARDEN,                   DATA_AIR_WARDEN             },
    { BOSS_ANRAPHET,                    DATA_ANRAPHET               },
    { BOSS_ISISET,                      DATA_ISISET                 },
    { BOSS_AMMUNAE,                     DATA_AMMUNAE                },
    { BOSS_SETESH,                      DATA_SETESH                 },
    { BOSS_RAJH,                        DATA_RAJH                   },
    { 0,                                0                           } // END
};

ObjectData const gameObjectData[] =
{
    { GO_DOODAD_ULDUM_DOOR_15,          DATA_ANHUUR_DOOR                },
    { GO_VAULT_OF_LIGHTS_DOOR,          DATA_VAULT_OF_LIGHTS_DOOR       },
    { GO_DOODAD_ULDUM_LIGHTMACHINE_02,  DATA_LIGHTMACHINE_EARTH         },
    { GO_DOODAD_ULDUM_LIGHTMACHINE_01,  DATA_LIGHTMACHINE_AIR           },
    { GO_DOODAD_ULDUM_LIGHTMACHINE_04,  DATA_LIGHTMACHINE_FIRE          },
    { GO_DOODAD_ULDUM_LIGHTMACHINE_03,  DATA_LIGHTMACHINE_WATER         },
    { GO_DOODAD_ULDUM_LASERBEAMS01,     DATA_LASERBEAMS_EARTH           },
    { GO_DOODAD_ULDUM_LASERBEAMS_01,    DATA_LASERBEAMS_AIR             },
    { GO_DOODAD_ULDUM_LASERBEAMS_03,    DATA_LASERBEAMS_FIRE            },
    { GO_DOODAD_ULDUM_LASERBEAMS_02,    DATA_LASERBEAMS_WATER           },
    { GO_SUN_MIRROR,                    DATA_ANRAPHET_SUN_MIRROR        },
    { GO_ANRAPHET_DOOR,                 DATA_ANRAPHET_DOOR              },
    { GO_LIFT_OF_THE_MAKERS,            DATA_LIFT_OF_THE_MAKERS         },
    { 0,                                0                               } //END
};

class instance_halls_of_origination : public InstanceMapScript
{
    public:
        instance_halls_of_origination() : InstanceMapScript(HoOScriptName, 644) { }

        struct instance_halls_of_origination_InstanceMapScript : public InstanceScript
        {
            instance_halls_of_origination_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);
                LoadObjectData(creatureData, gameObjectData);

                _brannIntroStarted = 0;
                _deadElementals = 0;

                RotateWardenPositions();
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                InstanceScript::OnGameObjectCreate(go);

                switch (go->GetEntry())
                {
                    case GO_HOO_TRANSIT_DEVICE: // 5 spawns
                    case GO_HOO_TRANSIT_DEVICE_2: // 1 spawn: elevator
                        _transitDeviceGUIDs.insert(go->GetGUID());
                        UpdateTransitDevice(go);
                        break;
                    case GO_LIFT_OF_THE_MAKERS:
                        go->SetTransportState(GO_STATE_TRANSPORT_ACTIVE);
                        go->SetTransportState(GO_STATE_TRANSPORT_STOPPED, 0);
                        break;
                    case GO_VAULT_OF_LIGHTS_DOOR:
                        if (_brannIntroStarted || GetBossState(DATA_VAULT_OF_LIGHTS) == DONE)
                            go->SetGoState(GO_STATE_ACTIVE);
                        break;
                    case GO_DOODAD_ULDUM_LASERBEAMS01:
                        if (GetBossState(DATA_EARTH_WARDEN) == DONE)
                            go->SetGoState(GO_STATE_ACTIVE);
                        break;
                    case GO_DOODAD_ULDUM_LASERBEAMS_01:
                        if (GetBossState(DATA_FIRE_WARDEN) == DONE)
                            go->SetGoState(GO_STATE_ACTIVE);
                        break;
                    case GO_DOODAD_ULDUM_LASERBEAMS_02:
                        if (GetBossState(DATA_AIR_WARDEN) == DONE)
                            go->SetGoState(GO_STATE_ACTIVE);
                        break;
                    case GO_DOODAD_ULDUM_LASERBEAMS_03:
                        if (GetBossState(DATA_WATER_WARDEN) == DONE)
                            go->SetGoState(GO_STATE_ACTIVE);
                        break;
                    case GO_SUN_MIRROR:
                    case GO_ANRAPHET_DOOR:
                        if (GetBossState(DATA_VAULT_OF_LIGHTS) == DONE)
                            go->SetGoState(GO_STATE_ACTIVE);
                        break;
                    case GO_ULDUM_TEMPLE: // Research about these objects.
                    case GO_REORIGINATION_MECHANISM_1:
                    case GO_REORIGINATION_MECHANISM_2:
                    case GO_REORIGINATION_MECHANISM_3:
                    case GO_REORIGINATION_MECHANISM_4:
                    case GO_REORIGINATION_MECHANISM_5:
                        go->SetGoState(GO_STATE_ACTIVE);
                        break;
                    case GO_DOODAD_ULDUM_LIGHTMACHINE_01:
                    case GO_DOODAD_ULDUM_LIGHTMACHINE_02:
                    case GO_DOODAD_ULDUM_LIGHTMACHINE_03:
                    case GO_DOODAD_ULDUM_LIGHTMACHINE_04:
                        if (GetBossState(DATA_VAULT_OF_LIGHTS) == DONE)
                            go->SetGoState(GO_STATE_ACTIVE);
                        break;
                    default:
                        break;
                }

                go->SetFarVisible(true);
            }

            void OnCreatureCreate(Creature* creature) override
            {
                InstanceScript::OnCreatureCreate(creature);

                switch (creature->GetEntry())
                {
                    case NPC_HOO_CAMEL:
                        _hooCamelGUIDs.insert(creature->GetGUID());
                        break;
                    case NPC_BEETLE_STALKER: // Must be active (sometimes they fail to summon adds, hopefully not anymore).
                        creature->setActive(true);
                        break;
                    case NPC_DUSTBONE_HORROR:
                    case NPC_JEWELED_SCARAB:
                        creature->SetInCombatWithZone();
                        break;
                    case BOSS_ANRAPHET: // Must be active (their AI runs the event at the Vault of Lights).
                    case NPC_BRANN_BRONZEBEARD_0:
                        creature->setActive(true);
                        break;
                    case NPC_FIRE_WARDEN: // random teleport spell + far-visibility
                    case NPC_EARTH_WARDEN:
                    case NPC_WATER_WARDEN:
                    case NPC_AIR_WARDEN:
                        creature->CastSpell(nullptr, _wardenPositionSpells[creature->GetEntry() - NPC_FIRE_WARDEN]);
                        creature->SetFarVisible(true);
                        break;
                    case NPC_STONE_TROGG_PILLAGER: // far-visibility
                    case NPC_STONE_TROGG_BRUTE:
                    case NPC_STONE_TROGG_ROCK_FLINGER:
                        if (GetBossState(DATA_VAULT_OF_LIGHTS) == DONE)
                            creature->DespawnOrUnsummon(0, Seconds(DAY));
                        creature->SetFarVisible(true);
                        break;
                    case NPC_SPATIAL_FLUX_TRASH:
                    case NPC_SPATIAL_ANOMALY:
                    case NPC_FLUX_ANIMATOR:
                    case NPC_STAR_SHARD:
                        creature->SearchFormation();
                        if (creature->GetFormation())
                            _isisetTrashGUIDs.insert(creature->GetGUID());
                        break;
                    case NPC_ALPHA_BEAM:
                        if (Creature* anraphet = GetCreature(DATA_ANRAPHET))
                            anraphet->AI()->JustSummoned(creature);
                    default:
                        break;
                }
            }

            void SetData(uint32 data, uint32 value) override
            {
                switch (data)
                {
                    case DATA_UPDATE_LASERBEAMS:
                        UpdateAllLaserBeams();
                        break;
                    case DATA_ISISET_PHASE:
                        _isisetPhase = value;
                        break;
                    case DATA_ISISET_ASTRAL_RAIN_ALIVE:
                        _isisetAstralRainAlive = value;
                        break;
                    case DATA_ISISET_CELESTIAL_CALL_ALIVE:
                        _isisetCelestialCallAlive = value;
                        break;
                    case DATA_ISISET_VEIL_OF_SKY_ALIVE:
                        _isisetVeilOfSkyAlive = value;
                        break;
                }
            }

            uint32 GetData(uint32 data) const override
            {
                switch (data)
                {
                    case DATA_DEAD_ELEMENTALS:
                        return _deadElementals;
                    case DATA_ISISET_PHASE:
                        return _isisetPhase;
                    case DATA_ISISET_ASTRAL_RAIN_ALIVE:
                        return _isisetAstralRainAlive;
                    case DATA_ISISET_CELESTIAL_CALL_ALIVE:
                        return _isisetCelestialCallAlive;
                    case DATA_ISISET_VEIL_OF_SKY_ALIVE:
                        return _isisetVeilOfSkyAlive;
                    default:
                        break;
                }

                return 0;
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                if (state == DONE) // Respawn transit devices if needed.
                    for (ObjectGuid guid : _transitDeviceGUIDs)
                        if (GameObject* transit = instance->GetGameObject(guid))
                            UpdateTransitDevice(transit);

                switch (type)
                {
                    case DATA_EARTHRAGER_PTAH:
                        if (state == IN_PROGRESS)
                        {
                            // Camels cannot be mounted during the boss fight.
                            for (ObjectGuid guid : _hooCamelGUIDs)
                                if (Creature* camel = instance->GetCreature(guid))
                                    camel->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                        }
                        else
                        {
                            // Make camels mountable again.
                            for (ObjectGuid guid : _hooCamelGUIDs)
                                if (Creature* camel = instance->GetCreature(guid))
                                    camel->SetFlag(UNIT_FIELD_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                        }
                        break;
                    case DATA_VAULT_OF_LIGHTS:
                        if (state == IN_PROGRESS)
                        {
                            HandleGameObject(ObjectGuid::Empty, true, GetGameObject(DATA_VAULT_OF_LIGHTS_DOOR));
                            DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_VAULT_OF_LIGHTS_START_EVENT);
                        }
                        else if (state == DONE)
                        {
                            DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET2, SPELL_VAULT_OF_LIGHTS_CREDIT);
                        }
                        break;
                    case DATA_FIRE_WARDEN:
                    case DATA_EARTH_WARDEN:
                    case DATA_WATER_WARDEN:
                    case DATA_AIR_WARDEN:
                        if (state == DONE)
                        {
                            UpdateAllLightMachines();
                            ++_deadElementals;
                            if (Creature* brann = GetCreature(DATA_BRANN_0))
                                brann->AI()->DoAction(ACTION_ELEMENTAL_DIED);
                        }
                        break;
                    default:
                        break;
                }

                return true;
            }

            void OnUnitDeath(Unit* unit) override
            {
                Creature* creature = unit->ToCreature();
                if (!creature)
                    return;

                switch (creature->GetEntry())
                {
                    case NPC_DUSTBONE_HORROR:
                    case NPC_JEWELED_SCARAB:
                        if (Creature* ptah = GetCreature(DATA_EARTHRAGER_PTAH))
                            ptah->GetAI()->DoAction(ACTION_PTAH_ADD_DIED);
                        break;
                    case NPC_FIRE_WARDEN: // We have to set boss states manually (wardens use SmartAI).
                    case NPC_EARTH_WARDEN: // To-do: check if smart scripts can handle this
                    case NPC_WATER_WARDEN:
                    case NPC_AIR_WARDEN:
                    {
                        uint32 data = creature->GetEntry() - WARDEN_ENTRY_DATA_DELTA;
                        SetBossState(data, IN_PROGRESS); // Needs to be set to IN_PROGRESS or else the gameobjects state won't be updated
                        SetBossState(data, DONE);
                        break;
                    }
                    case NPC_SPATIAL_ANOMALY:
                    case NPC_FLUX_ANIMATOR:
                    case NPC_STAR_SHARD:
                    {
                        CreatureGroup* group = creature->GetFormation();
                        if (!group)
                            return;

                        // Check if whole formation is dead, then despawn its leader
                        for (ObjectGuid guid : _isisetTrashGUIDs)
                            if (Creature* member = instance->GetCreature(guid))
                                if (member->GetEntry() != NPC_SPATIAL_FLUX_TRASH && member->GetFormation()->GetId() == group->GetId() && member->IsAlive())
                                    return;

                        // Despawn leader (Spatial Flux)
                        if (Creature* leader = group->getLeader())
                            leader->DespawnOrUnsummon();

                        break;
                    }
                    default:
                        break;
                }
            }

            void WriteSaveDataMore(std::ostringstream& data) override
            {
                data << _brannIntroStarted << ' ' << _deadElementals << ' ';
            
                for (uint8 i = 0; i < WARDEN_ENTRY_MAX_COUNT; i++)
                    data << _wardenPositionSpells[i] << ' ';
            }

            void ReadSaveDataMore(std::istringstream& data) override
            {
                data >> _brannIntroStarted >> _deadElementals;
                    
                for (uint8 i = 0; i < WARDEN_ENTRY_MAX_COUNT; i++)
                    data >> _wardenPositionSpells[i];
            }

        private:
            void RotateWardenPositions()
            {
                uint32 startAt = urand(0, WARDEN_ENTRY_MAX_COUNT - 1);
                for (uint32 i = 0; i < WARDEN_ENTRY_MAX_COUNT; i++)
                    _wardenPositionSpells[(i + startAt) % WARDEN_ENTRY_MAX_COUNT] = SPELL_TELEPORT_EARTH + i;
            }
            
            // Activated when warden dies (on SetBossState DONE).
            void UpdateAllLightMachines()
            {
                for (uint8 i = 0; i < WARDEN_ENTRY_MAX_COUNT; i++)
                {
                    uint32 positionIndex = _wardenPositionSpells[i] - SPELL_TELEPORT_EARTH;
                    HandleGameObject(ObjectGuid::Empty, GetBossState(DATA_FIRE_WARDEN + i) == DONE, GetGameObject(DATA_LIGHTMACHINE_EARTH + positionIndex));
                }
            }

            // Activated 9 seconds after warden dies (on SetData DATA_UPDATE_LASERBEAMS, called by Brann).
            void UpdateAllLaserBeams()
            {
                for (uint8 i = 0; i < WARDEN_ENTRY_MAX_COUNT; i++)
                {
                    uint32 positionIndex = _wardenPositionSpells[i] - SPELL_TELEPORT_EARTH;
                    HandleGameObject(ObjectGuid::Empty, GetBossState(DATA_FIRE_WARDEN + i) == DONE, GetGameObject(DATA_LIGHTMACHINE_EARTH + positionIndex));
                }
            }

            void UpdateTransitDevice(GameObject* transit)
            {
                if (transit->GetPositionX() < -900.f) // The southernmost transit: x = -934.576
                    transit->SetRespawnTime(GetBossState(DATA_TEMPLE_GUARDIAN_ANHUUR) == DONE ? -1 : DAY);
                else if (transit->GetPositionY() < -300.f) // The two easternmost transits: y = -337.028, y = -686.826
                    transit->SetRespawnTime(GetBossState(DATA_EARTHRAGER_PTAH) == DONE ? -1 : DAY);
                else // All other transits.
                    transit->SetRespawnTime(GetBossState(DATA_ANRAPHET) == DONE ? -1 : DAY);
            }
            
            GuidSet _transitDeviceGUIDs;
            GuidSet _hooCamelGUIDs;
            GuidSet _isisetTrashGUIDs;
            GuidSet _caveInStalkerGUIDs;
            uint32 _brannIntroStarted;
            uint32 _wardenPositionSpells[WARDEN_ENTRY_MAX_COUNT];
            uint32 _deadElementals;
            uint32 _isisetPhase;
            uint32 _isisetAstralRainAlive;
            uint32 _isisetCelestialCallAlive;
            uint32 _isisetVeilOfSkyAlive;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_halls_of_origination_InstanceMapScript(map);
        }
};

void AddSC_instance_halls_of_origination()
{
    new instance_halls_of_origination();
}