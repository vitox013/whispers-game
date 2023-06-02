#pragma once
#include "..\..\stdafx.h"
#include "..\Character\Character.h"
#include ".\Obstacle.h"

#define WALL_TEXTURE_PATH "assets/obstacle/wall.png"

namespace Whispers::Entity::Obstacle {
class Wall : public Obstacle {
   public:
    Wall(Vector2f pos, Vector2f size);
    ~Wall();
    void collision(Entity* entity, Vector2f ds = Vector2f(0.0f, 0.0f));
};
}  // namespace Whispers::Entity::Obstacle