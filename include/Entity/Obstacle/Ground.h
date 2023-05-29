#pragma once
#include "..\..\stdafx.h"
#include "..\Character\Character.h"
#include ".\Obstacle.h"

#define GROUND_TEXTURE_PATH "assets/ground.png"

namespace Whispers::Entity::Obstacle {
class Ground : public Obstacle {
   public:
    Ground(Vector2f pos, Vector2f size);
    ~Ground();
    void collision(Entity* entity, Vector2f ds = Vector2f(0.0f, 0.0f));
};
}  // namespace Whispers::Entity::Obstacle