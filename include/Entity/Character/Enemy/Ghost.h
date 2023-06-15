#pragma once

#include "./Enemy.h"

#define GHOST_SIZE_X 50.0f
#define GHOST_SIZE_Y 70.0f
#define GHOST_LIFE 3
#define GHOST_DAMAGE 1

namespace Whispers::Entity::Character::Enemy {
class Ghost : public Enemy {
   private:
    bool invisible;
    void init();

   public:
    Ghost(const sf::Vector2f pos, Player* player);
    void moveEnemy();
    bool getInvisible() const;
    void collision(Entity *other, Vector2f ds = Vector2f(0.0f, 0.0f));
    void updateAnimation();
    ~Ghost();
};
} 