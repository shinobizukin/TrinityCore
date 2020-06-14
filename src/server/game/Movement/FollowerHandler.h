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

#ifndef FollowerHandler_h__
#define FollowerHandler_h__

#include "Define.h"
#include "Optional.h"
#include <vector>
#include <utility>

class Unit;
struct Position;

constexpr uint8 MAX_FOLLOWERS_PER_ROW       = 6;
constexpr uint8 DEFAULT_ROW_FOLLOWERS       = 2;
constexpr float STRAIGHT_FOLLOW_DISTANCE    = 3.f;
constexpr float SIDE_FOLLOW_DISTANCE        = 3.3541f;

struct FollowerInfo
{
    Unit* Follower = nullptr;
    bool HasCustomSettings = false;
};

class TC_GAME_API FollowerHandler
{
public:
    FollowerHandler(Unit* target);

    // Re-calculates the follow offsets for all assigned followers to fill up gaps in the formation
    void ReorganizeFollowers();

    // Adds a follower to the owner and sets up the FollowMovementGenerator for it.
    void AddFollower(Unit* follower, bool catchUp = true, Optional<float> distance = nullptr, Optional<float> angle = nullptr);

    // Removes the follower from the follower set. Does NOT finalize the FollowMovementGenerator
    void RemoveFollower(Unit* follower);

    // Clears the follow movement of all followers and finalizes the FollowMovementGenerator
    void RemoveAllFollowers();

    // Calculates the follow offsets based on the position in the follower set
    void GetFollowOffsets(uint8 followerIndex, float& distance, float& relativeAngle);

private:
    Unit* _followTarget;
    std::vector<FollowerInfo> _followers;
};

#endif // FollowerHandler_h__
