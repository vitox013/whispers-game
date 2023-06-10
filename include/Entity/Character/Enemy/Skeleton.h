#pragma once

#include <chrono>
#include <random>

#include ".\Enemy.h"
#define SKELETON_SIZE_X 50.0f
#define SKELETON_SIZE_Y 70.0f
#define SKELETON_LIFE 3
#define SKELETON_DAMAGE 1

namespace Whispers::Entity::Character::Enemy {
class Skeleton : public Enemy {
   private:
    void init();
    float angerLevel;

   public:
    Skeleton(const sf::Vector2f pos, Player* player);
    ~Skeleton();
    void updatePosition();
    void collision(Entity *other, Vector2f ds = Vector2f(0.0f, 0.0f));
};
}  // namespace Whispers::Entity::Character::Enemy
