#pragma once
#include "..\..\stdafx.h"
#include "..\Entity.h"
#include "..\..\Animation\Animation.h"
#define PROJECTILE_SPEED 1.5f
#define PROJECTILE_SIZE_X 10.0f
#define PROJECTILE_SIZE_Y 10.0f
#define GRAVITY -1.2f
namespace Whispers::Entity::Projectile
{
    class Projectile : public Entity
    {
    protected:
        Animation::Animation animation;
        float Speed;
        Vector2f nordir;
        Vector2f postarget;
        Vector2f direction;
        Vector2f currentVel;
        bool side;

    public:
        Projectile(Vector2f pos, Vector2f target, bool sidei);
        ~Projectile();
        void collision(Entity *otherEntity,
                               Vector2f ds = Vector2f(0.0f, 0.0f));
        void update();
        void updateanimation();
        void DirectionCalc();
    };
}