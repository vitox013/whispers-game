#pragma once
#include "..\..\..\stdafx.h"
#include "..\Character.h"
#include "..\Player\Player.h"

#define CHASE_RAY_X 200.0f
#define CHASE_RAY_Y 200.0f
#define ENEMY_SPEED 60.0f

namespace Whispers::Entity::Character::Enemy {

class Enemy : public Character {
   private:
    Player* player;
    short randomMove;
    float dtAux;

    void randomMovement();

   public:
    Enemy(const Vector2f pos, const Vector2f size, const int life,
          const int damage, Player* pP, ID::ID id);
    ~Enemy();
    virtual void moveEnemy();
    virtual void update();
    void collision(Entity* other, Vector2f ds = Vector2f(0.0f, 0.0f));
};
}  // namespace Whispers::Entity::Character::Enemy
