#pragma once

#include ".\Enemy.h"

#define BOSS_SIZE_X 50.0f
#define BOSS_SIZE_Y 70.0f

namespace Whispers::Entity::Character::Enemy {
class Boss : public Enemy {
   private:
    void init();

   public:
    Boss(const sf::Vector2f pos, Player* player);
    ~Boss();
    void moveEnemy();
};
}  // namespace Whispers::Entity::Character::Enemy
