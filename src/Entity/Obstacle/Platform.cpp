#include "..\..\..\include\Entity\Obstacle\Platform.h"

using namespace Whispers::Entity::Obstacle;

Platform::Platform(Vector2f pos, Vector2f size)
    : Obstacle(pos, size, ID::ID::platform) {
    shape.setFillColor(Color::Green);
}

Platform::~Platform() {}

void Platform::collision(Entity* other, Vector2f ds) {
    Vector2f otherPos = other->getPosition();
    Vector2f otherSize = other->getSize();

    if (other->getId() == ID::ID::player || other->getId() == ID::ID::enemy) {
        collideObstacle(ds, static_cast<Character::Character*>(other));
    }
}

void Platform::collideObstacle(Vector2f ds, Character::Character* pChar) {
    Vector2f pCharPos = pChar->getPosition();
    Vector2f pCharSize = pChar->getSize();
    Vector2f speed = pChar->getSpeed();

    if (ds.x < 0.0f && ds.y < 0.0f) {
        if (ds.x > ds.y) {
            if (pCharPos.x < position.x) {
                pCharPos.x += ds.x;
            } else {
                pCharPos.x -= ds.x;
            }
            speed.x = 0.0f;
        } else {
            if (pCharPos.y < position.y) {
                pCharPos.y += ds.y;
                if (pChar->getId() == ID::ID::player) {
                    Character::Player* pPlayer =
                        static_cast<Character::Player*>(pChar);
                    pPlayer->canJump();
                }
            } else {
                pCharPos.y -= ds.y;
            }
            speed.y = 0.0f;
        }
    }
    pChar->setPosition(pCharPos);
    pChar->setSpeed(speed);
}