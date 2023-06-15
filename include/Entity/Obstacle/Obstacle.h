#pragma once
#include "../../stdafx.h"
// #include "../Character/Enemy/Enemy.h"
#include "../Character/Player/Player.h"
#include "../Character/Enemy/Boss.h"
#include "../Entity.h"

namespace Whispers::Entity::Obstacle {
class Obstacle : public Entity {
   protected:
    Texture texture;

   public:
    Obstacle(Vector2f pos, Vector2f size, ID::ID id, const char* path);
    ~Obstacle();
    virtual void collision(Entity* otherEntity,
                           Vector2f ds = Vector2f(0.0f, 0.0f)) = 0;
    virtual void collideObstacle(Vector2f ds, Character::Character* pChar);
    void update();
};
}  // namespace Whispers::Entity::Obstacle