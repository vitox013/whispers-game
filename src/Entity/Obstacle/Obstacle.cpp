#include "..\..\..\include\Entity\Obstacle\Obstacle.h"

using namespace Whispers::Entity::Obstacle;

Obstacle::Obstacle(Vector2f pos, Vector2f size, ID::ID id)
    : Entity(pos, size, id) {}

Obstacle::~Obstacle() {}

void Obstacle::update() { draw(); }