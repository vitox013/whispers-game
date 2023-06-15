#pragma once

#include "./Obstacle.h"

#define TRAP_TEXTURE_PATH "assets/obstacle/trap.png"

namespace Whispers::Entity::Obstacle {
class Trap : public Obstacle {
   private:
    const int damage;

   public:
    Trap(Vector2f pos, Vector2f size);
    ~Trap();
    void collision(Entity* entity, Vector2f ds = Vector2f(0.0f, 0.0f));
    void collideObstacle(Vector2f ds, Character::Character* pChar);
    const int getDamage() const { return damage; }
};
}  // namespace Whispers::Entity::Obstacle