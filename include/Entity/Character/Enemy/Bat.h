#pragma once

#include ".\Enemy.h"
#include "..\..\Projectile\Projectile.h"
#include "..\..\..\List\EntityList.h"

#define BAT_SIZE_X 50.0f
#define BAT_SIZE_Y 70.0f

#define SHOOT_RAY_X 400.0f
#define SHOOT_RAY_Y 400.0f

namespace Whispers::Entity::Character::Enemy
{
    class Bat : public Enemy
    {
    private:
        void init();
        List::EntityList *projlist;
        Time cooldown;

    public:
        Bat(const sf::Vector2f pos, Player *player, List::EntityList * projelist);
        ~Bat();
        void update();
        void CreatePojectile(Vector2f target);
    };
} // namespace Whispers::Entity::Character::Enemy
