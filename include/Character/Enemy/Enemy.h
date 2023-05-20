#pragma once
#include "..\..\stdafx.h"
#include "..\Character.h"
#include "..\Player\Player.h"

#define CHASE_RAY_X 200.0f
#define CHASE_RAY_Y 200.0f

namespace Whispers {
namespace Character {
namespace Enemy {
class Enemy : public Character {
   private:
    Player* player;
    short randomMove;
    Clock clock;
    void init();

   public:
    Enemy(const Vector2f pos, const Vector2f size,
          Whispers::Character::Player* pP);
    ~Enemy();
    void chasePlayer(Vector2f playerPos, Vector2f EnemyPos);
    void randomMovement();
    void move();
};
}  // namespace Enemy
}  // namespace Character
}  // namespace Whispers
