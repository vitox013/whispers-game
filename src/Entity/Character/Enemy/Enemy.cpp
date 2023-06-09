#include "../../../../include/Entity/Character/Enemy/Enemy.h"

using namespace Whispers::Entity::Character;

Enemy::Enemy::Enemy(const Vector2f pos, const Vector2f size, const int life,
                    const bool canFly, const int damage, Player* pP, ID::ID id)
    : Character(pos, size, ENEMY_SPEED, life, canFly, damage, id),
      player(pP),
      dtAux(0.0f) {
    srand(time(NULL));
    randomMove = rand() % 3;
    if (randomMove == 0) {
        stop();
    } else if (randomMove == 1) {
        walk(true);
    } else {
        walk(false);
    }
}

Enemy::Enemy::~Enemy() {}

void Enemy::Enemy::randomMovement() {
    if (dtAux >= 1.0f) {
        randomMove = rand() % 12;
        if (randomMove == 0) {
            stop();
        } else if (randomMove == 1) {
            walk(true);

        } else if (randomMove == 2) {
            walk(false);
        }
        dtAux = 0.0f;
    }
}

void Enemy::Enemy::moveEnemy() {
    Vector2f playerPos = player->getPosition();
    Vector2f enemyPos = getPosition();

    if (fabs(playerPos.x - enemyPos.x) <= CHASE_RAY_X &&
        fabs(playerPos.y - enemyPos.y) <= CHASE_RAY_Y) {
        if ((playerPos.x - enemyPos.x < 10.0f) &&
            (playerPos.x - enemyPos.x > -10.0f)) {
            stop();
        } else if (playerPos.x - enemyPos.x > 0.0f) {
            walk(false);
        } else {
            walk(true);
        }
    } else {
        randomMovement();
    }
}

void Enemy::Enemy::update() {
    moveEnemy();
    updatePosition();
    dtAux += clock.getElapsedTime().asSeconds() * 100;
    clock.restart();
    updateAnimation();
}
void Enemy::Enemy::collision(Entity* other, Vector2f ds) { stop(); }