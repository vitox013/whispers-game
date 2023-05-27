#pragma once
#include "..\..\stdafx.h"
#include "..\Entity.h"

namespace Whispers::Entity::Projectile
{
    class Projectile : public Entity
    {
    protected:
        Texture texture;

    public:
        Projectile(Vector2f pos, Vector2f size, ID::ID id);
        ~Projectile();
        virtual void collision(Entity *otherEntity,
                               Vector2f ds = Vector2f(0.0f, 0.0f)) = 0;
        void update();
    };
}