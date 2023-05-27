#include "..\..\..\include\Entity\Obstacle\Obstacle.h"

using namespace Whispers::Entity::Obstacle;

Obstacle::Obstacle(Vector2f pos, Vector2f size, ID::ID id, const char* path)
    : Entity(pos, size, id) {
    texture = pGraphic->loadTexture(path);
    shape.setTexture(&texture);
}

Obstacle::~Obstacle() {}

void Obstacle::update() { draw(); }