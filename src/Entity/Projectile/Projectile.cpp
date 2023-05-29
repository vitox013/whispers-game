#pragma once
#include "..\..\..\include\Entity\Projectile\Projectile.h"

using namespace Whispers::Entity::Projectile;

Projectile::Projectile(Vector2f pos, Vector2f size, Vector2f target)
    : Entity(pos, size, ID::ID::empty), Speed{PROJECTILE_SPEED}
{
    shape.setFillColor(Color::Blue);
    postarget = target;
    DirectionCalc();
}

Projectile::~Projectile()
{
}

void Projectile::update()
{
    currentVel = nordir * Speed;
    setPosition(Vector2f(currentVel.x + position.x, currentVel.y + position.y));
    draw();
}
void Projectile::DirectionCalc()
{
    direction = Vector2f((postarget.x - position.x)/2,(postarget.y - position.y)/2);
    nordir = direction / sqrt(pow(direction.x, 2.0f) + pow(direction.y, 2.0f));
}
void Projectile::collision(Entity* OtherEntity, Vector2f ds)
{
    shape.setFillColor(Color::Red);
}