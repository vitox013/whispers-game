#include "..\..\..\include\Entity\Obstacle\Web.h"

using namespace Whispers::Entity::Obstacle;

Web::Web(Vector2f pos, Vector2f size)
    : Obstacle(pos, size, ID::ID::web, WEB_TEXTURE_PATH), slowness(100) {}

Web::~Web() {}

void Web::collision(Entity* other, Vector2f ds) {
    if (other->getId() == ID::ID::player || other->getId() == ID::ID::enemy ||
        other->getId() == ID::ID::skeleton || other->getId() == ID::ID::bat ||
        other->getId() == ID::ID::boss) {
        collideObstacle(ds, static_cast<Character::Character*>(other));
    }
}

void Web::collideObstacle(Vector2f ds, Character::Character* pChar) {
    Vector2f pCharSize = pChar->getSize();
    Vector2f speed = pChar->getSpeed();

    if (pChar->getId() == ID::ID::player) {
        speed.x -= slowness;
    }

    pChar->setSpeed(speed);
}
