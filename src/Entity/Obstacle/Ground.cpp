#include "..\..\..\include\Entity\Obstacle\Ground.h"

using namespace Whispers::Entity::Obstacle;

Ground::Ground(Vector2f pos, Vector2f size, int type)
    : Obstacle(pos, size, ID::ID::ground,
               type == 1 ? GROUND_TEXTURE_MIDNIGHT : GROUND_TEXTURE_GRAVEYARD) {
}

Ground::~Ground() {}

void Ground::collision(Entity* other, Vector2f ds) {
    Vector2f otherPos = other->getPosition();
    Vector2f otherSize = other->getSize();

    if (other->getId() == ID::ID::player || other->getId() == ID::ID::enemy ||
        other->getId() == ID::ID::skeleton || other->getId() == ID::ID::bat ||
        other->getId() == ID::ID::boss) {
        collideObstacle(ds, static_cast<Character::Character*>(other));
    }
}
