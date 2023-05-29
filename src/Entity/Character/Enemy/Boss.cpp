#include "..\..\..\..\include\Entity\Character\Enemy\Boss.h"

using namespace Whispers::Entity::Character::Enemy;

Boss::Boss(const sf::Vector2f pos, Player* player)
    : Enemy(pos, sf::Vector2f(BOSS_SIZE_X, BOSS_SIZE_Y), player, ID::ID::boss) {
    init();
}

Boss::~Boss() {}

void Boss::init() {
    animation.addAnimation("assets/character/enemy/boss/idle.png", "idle", 9,
                           0.088f, sf::Vector2f(2.5, 2.5));
    animation.addAnimation("assets/character/enemy/boss/walk.png", "walk", 6,
                           0.2f, sf::Vector2f(3.0, 3.0));
    shape.setOrigin(sf::Vector2f(size.x / 2.5f, size.y / 3.0f));
}

void Boss::moveEnemy() {
    Vector2f playerPos = getPlayer()->getPosition();
    Vector2f enemyPos = getPosition();

    if (fabs(playerPos.x - enemyPos.x) <= CHASE_RAY_X &&
        fabs(playerPos.y - enemyPos.y) <= CHASE_RAY_Y) {
        if (playerPos.x - enemyPos.x > 0.0f) {
            walk(false);
        } else {
            walk(true);
        }
    } else {
        stop();
    }
}
