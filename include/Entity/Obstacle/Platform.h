#pragma once
#include "..\..\stdafx.h"
#include "..\Character\Character.h"
#include "..\Character\Enemy\Enemy.h"
#include "..\Character\Player\Player.h"
#include ".\Obstacle.h"

#define PLATFORM_TEXTURE_PATH "assets/platform.png"

namespace Whispers::Entity::Obstacle {
class Platform : public Obstacle {
   public:
    Platform(Vector2f pos, Vector2f size);
    ~Platform();
    void Colission(Entity* entity, Vector2f ds = Vector2f(0.0f, 0.0f));
    void collideObstacle(Vector2f ds, Character::Character* pChar);
};
}  // namespace Whispers::Entity::Obstacle