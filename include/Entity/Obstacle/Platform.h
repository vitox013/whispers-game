#pragma once
#include "..\..\stdafx.h"
#include "..\Character\Character.h"
#include ".\Obstacle.h"

#define PLATFORM_TEXTURE_PATH "assets/platform.png"

namespace Whispers::Entity::Obstacle {
class Platform : public Obstacle {
   public:
    Platform(Vector2f pos, Vector2f size);
    ~Platform();
    void collision(Entity* entity, Vector2f ds = Vector2f(0.0f, 0.0f));
};
}  // namespace Whispers::Entity::Obstacle