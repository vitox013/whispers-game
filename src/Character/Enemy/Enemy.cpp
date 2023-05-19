#include "../../../include/Character/Enemy/Enemy.h"

using namespace Whispers;
using namespace Character;

Enemy::Enemy::Enemy(const Vector2f pos, const Vector2f size, Player* pP)
    : Character(pos, size), player(pP), clock() {
    shape.setFillColor(Color::Red);
    init();
    srand(time(NULL));
    randomMove = rand() % 4;
}

Enemy::Enemy::~Enemy() {}

void Enemy::Enemy::init() { speed = Vector2f(0.025f, 0.025f); }

void Enemy::Enemy::chasePlayer(Vector2f pP, Vector2f eP) {
    if (pP.x - eP.x > 0.0f) {
        shape.move(speed.x, 0.0f);
    } else {
        shape.move(-speed.x, 0.0f);
    }
    if (pP.y - eP.y > 0.0f) {
        shape.move(0.0f, speed.y);
    } else {
        shape.move(0.0f, -speed.y);
    }
}

void Enemy::Enemy::randomMovement() {
    if (randomMove == 0) {
        shape.move(-speed.x, 0.0f);
    } else if (randomMove == 1) {
        shape.move(speed.x, 0.0f);
    } else if (randomMove == 2) {
        shape.move(0.0f, -speed.y);
    } else {
        shape.move(0.0f, speed.y);
    }

    float dt = clock.getElapsedTime().asSeconds();
    if (dt >= 1.0f) {
        randomMove = rand() % 4;
        clock.restart();
    }
}

void Enemy::Enemy::move() {
    Vector2f playerPos = player->getShape().getPosition();
    Vector2f enemyPos = shape.getPosition();

    if (fabs(playerPos.x - enemyPos.x) <= CHASE_RAY_X &&
        fabs(playerPos.y - enemyPos.y) <= CHASE_RAY_Y) {
        chasePlayer(playerPos, enemyPos);
    } else {
        randomMovement();
    }
}