#pragma once
#include "..\..\..\include\Entity\Projectile\Projectile.h"

using namespace Whispers::Entity::Projectile;

Projectile::Projectile(Vector2f pos, Vector2f size, ID::ID id)
    : Entity(pos, size, id)
{
}

Projectile::~Projectile()
{
}

void Projectile::update()
{
    draw();
}