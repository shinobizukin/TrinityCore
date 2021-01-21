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

#ifndef TRINITY_WAYPOINTDEFINES_H
#define TRINITY_WAYPOINTDEFINES_H

#include "Define.h"
#include "G3D/Vector3.h"
#include <vector>

enum WaypointMoveType
{
    WAYPOINT_MOVE_TYPE_WALK,
    WAYPOINT_MOVE_TYPE_RUN,
    WAYPOINT_MOVE_TYPE_LAND,
    WAYPOINT_MOVE_TYPE_TAKEOFF,

    WAYPOINT_MOVE_TYPE_MAX
};

struct WaypointNode
{
    WaypointNode() : Id(0), X(0.f), Y(0.f), Z(0.f), Orientation(0.f), Velocity(0.f), Delay(0), EventId(0), MoveType(WAYPOINT_MOVE_TYPE_RUN), EventChance(0) { }
    WaypointNode(uint32 id, float x, float y, float z, float orientation = 0.f, float velocity = 0.f, uint32 delay = 0) :
        Id(id), X(x), Y(y), Z(z), Orientation(orientation), Velocity(velocity), Delay(delay)
    {
        EventId = 0;
        MoveType = WAYPOINT_MOVE_TYPE_WALK;
        EventChance = 100;
    }

    uint32 Id;
    float X, Y, Z, Orientation;
    float Velocity;
    int32 Delay;
    uint32 EventId;
    uint32 MoveType;
    uint8 EventChance;
    std::vector<G3D::Vector3> SplinePoints;
};

struct WaypointPath
{
    WaypointPath() : Id(0) { }
    WaypointPath(uint32 _id, std::vector<WaypointNode>&& _nodes)
    {
        Id = _id;
        Nodes = _nodes;
    }

    std::vector<WaypointNode> Nodes;
    uint32 Id;
};

#endif
