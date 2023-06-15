#include "../../../include/Entity/Obstacle/Obstacle.h"

using namespace Whispers::Entity::Obstacle;

Obstacle::Obstacle(Vector2f pos, Vector2f size, ID::ID id, const char* path)
    : Entity(pos, size, id) {
    texture = pGraphic->loadTexture(path);
    shape.setTexture(&texture);
}

Obstacle::~Obstacle() {}

void Obstacle::collideObstacle(Vector2f ds, Character::Character* pChar) {
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
                if (pChar->getId() == ID::ID::player || pChar->getId() == ID::ID::player2) {
                    Character::Player* pPlayer =
                        static_cast<Character::Player*>(pChar);
                    pPlayer->canJump();
                }else if (pChar->getId() == ID::ID::boss) {
                    Character::Enemy::Boss* pBoss =
                        static_cast<Character::Enemy::Boss*>(pChar);
                    pBoss->canJump();
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

void Obstacle::update() { draw(); }