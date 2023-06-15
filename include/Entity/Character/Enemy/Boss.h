#pragma once

#include "./Enemy.h"

#define BOSS_SIZE_X 50.0f
#define BOSS_SIZE_Y 70.0f
#define BOSS_LIFE 20
#define BOSS_DAMAGE 3

namespace Whispers::Entity::Character::Enemy {
class Boss : public Enemy {
   private:
    void init();
    const std::chrono::milliseconds attackDuration{1000};
    bool onFloor;
   public:
    Boss(const sf::Vector2f pos, Player* player);
    ~Boss();
    void jump();
    void canJump();
    void collision(Entity *other, Vector2f ds = Vector2f(0.0f, 0.0f));
    void updateAnimation();
    void updatePosition();
    void moveEnemy();
    void attack(const bool isAttacking);
};
}  // namespace Whispers::Entity::Character::Enemy
