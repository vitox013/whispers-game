#pragma once

#include "..\Entity\Character\Enemy\Bat.h"
#include "..\Entity\Character\Enemy\Boss.h"
#include "..\Entity\Character\Enemy\Enemy.h"
#include "..\Entity\Character\Enemy\Skeleton.h"
#include "..\Entity\Character\Player\Player.h"
#include "..\Entity\Obstacle\Ground.h"
#include "..\Entity\Obstacle\Platform.h"
#include "..\Entity\Obstacle\Trap.h"
#include "..\Entity\Obstacle\Wall.h"
#include "..\List\EntityList.h"

using namespace Whispers::Entity::Character;

namespace Whispers::Builder {
class EntityBuilder {
   private:
    Player* pPlayer;
    void verifyPlayer();

   public:
    EntityBuilder(Player* pPlayer);
    EntityBuilder();
    ~EntityBuilder();
    Entity::Entity* createEntity(const ID::ID id, const Vector2f pos, List::EntityList* projelist = nullptr);
};
}  // namespace Whispers::Builder