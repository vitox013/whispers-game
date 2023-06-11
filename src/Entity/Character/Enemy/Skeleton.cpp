#include "..\..\..\..\include\Entity\Character\Enemy\Skeleton.h"

using namespace Whispers::Entity::Character::Enemy;

Skeleton::Skeleton(const sf::Vector2f pos, Player *player)
    : Enemy(pos, sf::Vector2f(SKELETON_SIZE_X, SKELETON_SIZE_Y), SKELETON_LIFE,
            false, SKELETON_DAMAGE, player, ID::ID::skeleton) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 gen(seed);
    std::uniform_int_distribution<> numRandom(1, 2);
    angerLevel = numRandom(gen);
    damage = SKELETON_DAMAGE * angerLevel;

    if (angerLevel == 2) {
        shape.setFillColor(sf::Color::Red);
    }
    init();
}

Skeleton::~Skeleton() {}

void Skeleton::init() {
    animation.addAnimation("assets/character/enemy/skeleton/idle.png", "idle",
                           4, 0.3f, sf::Vector2f(4.0, 4.0));
    animation.addAnimation("assets/character/enemy/skeleton/walk.png", "walk",
                           4, 0.2f, sf::Vector2f(4.0, 4.0));
    animation.addAnimation("assets/character/enemy/skeleton/hurt.png",
                           "hurt", 4, 0.25f, sf::Vector2f(4.0, 4.0));
    shape.setOrigin(sf::Vector2f(size.x / 2.5f, size.y / 3.0f));
}

void Skeleton::updatePosition() {
    sf::Time deltaTime = clock.restart();
    float dt = deltaTime.asSeconds();
    Vector2f ds(0.0f, 0.0f);

    if (isAlive) {
        if (canWalk && !takeDamage) {
            ds.x = speed.x * dt * angerLevel;

            if (faceLeft) {
                ds.x *= -1;
            }
        } else if (takeDamage) {
            // knockback
            if (faceLeft) {
                ds.x = speed.x * dt * 1.2;
            } else {
                ds.x = -speed.x * dt * 1.2;
            }
        }

        speed.y += GRAVITY * dt;
        ds.y = speed.y * GRAVITY;
        
        setPosition(Vector2f(position.x + ds.x, position.y + ds.y));

        speed.x = maxSpeed;
    }

    draw();
}

void Skeleton::collision(Entity *other, Vector2f ds) {
    if (other->getId() == ID::ID::player || other->getId() == ID::ID::player2) {
        if (player->getIsInvincible() == false &&
            player->getIsAttacking() == false) {
            Player *player = static_cast<Player *>(other);
            Vector2f playerSpeed = player->getSpeed();
            playerSpeed.y = -sqrt(1.2f * GRAVITY * JUMP_SIZE);
            player->setSpeed(playerSpeed);
            player->setTakeDamage(true);
            player->setLife(player->getLife() - damage);
            player->setInvincible(true);
        }
    }
}
