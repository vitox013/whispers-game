#pragma once
#include "..\..\..\include\Entity\Projectile\Projectile.h"

using namespace Whispers::Entity::Projectile;

Projectile::Projectile(Vector2f pos, Vector2f target, const bool sidei)
    : Entity(pos, sf::Vector2f(PROJECTILE_SIZE_X, PROJECTILE_SIZE_Y), 
    ID::ID::Projectile), 
    Speed(PROJECTILE_SPEED),
    animation(&shape),
    postarget (target),
    side(sidei),
    damage(PROJECTILE_DAMAGE)
{
    
    //shape.setFillColor(Color::Blue);
    animation.addAnimation("assets/projectile/9_2.png", "Angle", 6,
                           0.1f, sf::Vector2f(6.0, 4.0));
    animation.addAnimation("assets/projectile/9_1.png", "straight", 6,
                           0.1f, sf::Vector2f(6.0, 4.0));
    DirectionCalc();
    if (side == true)
    {
        side = false;
    }else
    {
        side = true;
    }
    
}

Projectile::~Projectile()
{
}

void Projectile::update()
{
    currentVel.x = nordir.x * Speed;
    currentVel.y = nordir.y * Speed;// * GRAVITY;
    setPosition(Vector2f(currentVel.x + position.x, currentVel.y + position.y));
    updateanimation();
    draw();
}
void Projectile::DirectionCalc()
{
    direction = Vector2f((postarget.x - position.x) / 2, (postarget.y - position.y) / 2);
    nordir = direction / sqrt(pow(direction.x, 2.0f) + pow(direction.y, 2.0f));
}
void Projectile::collision(Entity *OtherEntity, Vector2f ds)
{
    shape.setFillColor(Color::Red);
}
void Projectile::updateanimation()
{
    //std::cout << (float)nordir.x << "," << (float)nordir.y << endl;
    if (nordir.x == 1.f || nordir.y == 1.f ||
        nordir.x == -1.f || nordir.y == -1.f)
    {
        animation.update(side, "straight");
    }
    else
    {
        animation.update(side, "Angle");
    }
}

int Projectile::getDamage()
{
    return damage;
}