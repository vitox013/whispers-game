#include "..\..\..\include\Entity\Obstacle\Platform.h"

using namespace Whispers::Entity::Obstacle;

Platform::Platform(Vector2f pos, Vector2f size)
    : Obstacle(pos, size, ID::ID::platform, PLATFORM_TEXTURE_PATH) {}

Platform::~Platform() {}

void Platform::collision(Entity* other, Vector2f ds) {
    Vector2f otherPos = other->getPosition();
    Vector2f otherSize = other->getSize();

    if (other->getId() == ID::ID::player || other->getId() == ID::ID::enemy) {
        collideObstacle(ds, static_cast<Character::Character*>(other));
    }
}
