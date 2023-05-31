#pragma once

#include ".\Enemy.h"

#define BOSS_SIZE_X 50.0f
#define BOSS_SIZE_Y 70.0f
#define BOSS_LIFE 20
#define BOSS_DAMAGE 3

namespace Whispers::Entity::Character::Enemy {
class Boss : public Enemy {
   private:
    void init();

   public:
    Boss(const sf::Vector2f pos, Player* player);
    ~Boss();
};
}  // namespace Whispers::Entity::Character::Enemy
