#include "..\..\..\..\include\Entity\Character\Enemy\Bat.h"

using namespace Whispers::Entity::Character::Enemy;

Bat::Bat(const sf::Vector2f pos, Player *player, List::EntityList *projelist)
    : Enemy(pos, sf::Vector2f(BAT_SIZE_X, BAT_SIZE_Y), BAT_LIFE, true,
            BAT_DAMAGE, player, ID::ID::bat),
      projlist{projelist},
      cooldown{clock.getElapsedTime()} {
    init();
}

Bat::~Bat() {}

void Bat::init() {
    animation.addAnimation("assets/character/enemy/bat/idle.png", "idle", 4,
                           0.3f, sf::Vector2f(1.0, 1.0));
    animation.addAnimation("assets/character/enemy/bat/walk.png", "walk", 4,
                           0.2f, sf::Vector2f(1.0, 1.0));
    shape.setOrigin(sf::Vector2f(size.x / 2.5f, size.y / 3.0f));
}
void Bat::CreatePojectile(Vector2f target) {
    Projectile::Projectile *nProj =
        new Projectile::Projectile(getPosition(), target, faceLeft);
    projlist->addEntity(static_cast<Entity *>(nProj));
}

void Bat::moveEnemy() {
    Vector2f playerPos = player->getPosition();
    Vector2f enemyPos = getPosition();

    if (fabs(playerPos.x - enemyPos.x) <= 800 &&
        fabs(playerPos.y - enemyPos.y) <= 800) {
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
void Bat::update() {
    moveEnemy();
    updatePosition();
    if ((cooldown.asSeconds() * 30) > 10.0f) {
        if (fabs(player->getPosition().x - getPosition().x) <= SHOOT_RAY_X &&
            fabs(player->getPosition().y - getPosition().y) <= SHOOT_RAY_Y) {
            CreatePojectile(player->getPosition());
            cooldown = clock.restart();
        }
    } else {
        // cout << cooldown.asSeconds() * 100 << endl;
        cooldown += clock.getElapsedTime();
    }
    dtAux += clock.getElapsedTime().asSeconds() * 100;
    clock.restart();
    updateAnimation();
}