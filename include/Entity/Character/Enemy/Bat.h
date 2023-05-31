#pragma once

#include ".\Enemy.h"

#define BAT_SIZE_X 50.0f
#define BAT_SIZE_Y 70.0f
#define BAT_LIFE 1
#define BAT_DAMAGE 1

namespace Whispers::Entity::Character::Enemy {
class Bat : public Enemy {
   private:
    void init();

   public:
    Bat(const sf::Vector2f pos, Player* player);
    ~Bat();
};
}  // namespace Whispers::Entity::Character::Enemy
