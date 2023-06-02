#pragma once

#include ".\Obstacle.h"

#define WEB_TEXTURE_PATH "assets/obstacle/web.png"

namespace Whispers::Entity::Obstacle {
class Web : public Obstacle {
   private:
    const int slowness;

   public:
    Web(Vector2f pos, Vector2f size);
    ~Web();
    void collision(Entity* entity, Vector2f ds = Vector2f(0.0f, 0.0f));
    void collideObstacle(Vector2f ds, Character::Character* pChar);
    const int getSlowness() const { return slowness; }
};
}  // namespace Whispers::Entity::Obstacle