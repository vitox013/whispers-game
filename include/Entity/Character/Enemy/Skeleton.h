#pragma once

#include ".\Enemy.h"

#define SKELETON_SIZE_X 50.0f
#define SKELETON_SIZE_Y 70.0f

namespace Whispers::Entity::Character::Enemy {
class Skeleton : public Enemy {
   private:
    void init();

   public:
    Skeleton(const sf::Vector2f pos, Player* player);
    ~Skeleton();
};
}  // namespace Whispers::Entity::Character::Enemy
