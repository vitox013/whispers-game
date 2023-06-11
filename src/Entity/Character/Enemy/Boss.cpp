#include "..\..\..\..\include\Entity\Character\Enemy\Boss.h"

using namespace Whispers::Entity::Character::Enemy;

Boss::Boss(const sf::Vector2f pos, Player* player)
    : Enemy(pos, sf::Vector2f(BOSS_SIZE_X, BOSS_SIZE_Y), BOSS_LIFE, false,
            BOSS_DAMAGE, player, ID::ID::boss),
      onFloor(true) {
    init();
}

Boss::~Boss() {}

void Boss::init() {
    animation.addAnimation("assets/character/enemy/boss/idle.png", "idle", 9,
                           0.1f, sf::Vector2f(4.0, 2.4));
    animation.addAnimation("assets/character/enemy/boss/walk.png", "walk", 4,
                           0.19f, sf::Vector2f(3.0, 2.4));
    animation.addAnimation("assets/character/enemy/boss/hurt.png", "hurt", 5,
                           0.1f, sf::Vector2f(4.0, 2.4));
    animation.addAnimation("assets/character/enemy/boss/attack.png", "attack",
                           10, 0.1f, sf::Vector2f(4.0, 3.0));
    shape.setOrigin(sf::Vector2f(size.x / 3.0f, size.y / 2.0f));
}

void Boss::jump() {
    if (onFloor && !takeDamage) {
        speed.y = -sqrt(2.0f * GRAVITY * JUMP_SIZE);
        onFloor = false;
    }
}

void Boss::canJump() { onFloor = true; }

void Boss::collision(Entity* other, sf::Vector2f ds) {
    Character* character = static_cast<Character*>(other);

    switch (other->getId()) {
        case ID::ID::player:
            attack(true);
            if (isAttacking && character->getIsInvincible() == false &&
                !takeDamage) {
                character->setTakeDamage(true);
                character->setLife(character->getLife() - damage);
                character->setInvincible(true);
            }
            break;
        case ID::ID::player2:
            attack(true);
            if (isAttacking && character->getIsInvincible() == false &&
                !takeDamage) {
                character->setTakeDamage(true);
                character->setLife(character->getLife() - damage);
                character->setInvincible(true);
            }
            break;
        default:
            break;
    }
}

void Boss::updateAnimation() {
    if (takeDamage) {
        animation.update(faceLeft, "hurt");
        canWalk = false;

        if (!isDamageAnimationActive) {
            damageStartTime =
                std::chrono::steady_clock::now();  // Inicia o temporizador
                                                   // quando a animação de
                                                   // dano começa
            isDamageAnimationActive = true;
        } else {
            auto elapsedTime =
                std::chrono::steady_clock::now() -
                damageStartTime;  // Calcula o tempo decorrido desde o
                                  // início da animação de dano

            if (elapsedTime >= damageDuration) {
                takeDamage = false;  // Restaura a capacidade de andar após
                                     // a conclusão da animação de dano
                isDamageAnimationActive = false;
            }
        }
    } else if (isAttacking && !takeDamage) {
        animation.update(faceLeft, "attack");
        if (!isAttackingAnimationActive) {
            attackStartTime = std::chrono::steady_clock::now();
            isAttackingAnimationActive = true;
        } else {
            auto elapsedTime =
                std::chrono::steady_clock::now() - attackStartTime;
            if (elapsedTime >= attackDuration) {
                isAttacking = false;
                size = Vector2f(BOSS_SIZE_X, BOSS_SIZE_Y);
                isAttackingAnimationActive = false;
            }
        }
    } else if (canWalk && !takeDamage) {
        animation.update(faceLeft, "walk");
    } else if (!takeDamage && !isAttacking) {
        animation.update(faceLeft, "idle");
    }
    auto elapsedTime =
        std::chrono::steady_clock::now() - invincibilityStartTime;
    if (elapsedTime >= invincibilityDuration) {
        // Set invincibility to false
        isInvincible = false;
    }
}

void Boss::updatePosition() {
    sf::Time deltaTime = clock.restart();
    float dt = deltaTime.asSeconds();
    Vector2f ds(0.0f, 0.0f);

    if (isAlive) {
        if (canWalk && !takeDamage && !isAttacking) {
            ds.x = speed.x * dt * 1.2;

            if (faceLeft) {
                ds.x *= -1;
            }
        } else if (takeDamage) {
            // knockback
            if (faceLeft) {
                ds.x = speed.x * dt;
            } else {
                ds.x = -speed.x * dt;
            }
        }

        speed.y += GRAVITY * dt;
        ds.y = speed.y * GRAVITY;

        setPosition(Vector2f(position.x + ds.x, position.y + ds.y));

        speed.x = maxSpeed;
    }

    draw();
}

void Boss::moveEnemy() {
    Vector2f playerPos = player->getPosition();
    Vector2f enemyPos = getPosition();

    if (fabs(playerPos.x - enemyPos.x) <= 500 &&
        fabs(playerPos.y - enemyPos.y) <= CHASE_RAY_Y) {
        if ((playerPos.x - enemyPos.x < 10.0f) &&
            (playerPos.x - enemyPos.x > -10.0f)) {
            jump();
            stop();
        } else if (playerPos.x - enemyPos.x > 0.0f) {
            walk(false);
        } else {
            walk(true);
        }
    } else {
        stop();
    }
}

void Boss::attack(const bool isAttacking) {
    canWalk = false;
    if (isAttacking) {
        this->isAttacking = true;
        size = Vector2f(BOSS_SIZE_X * 1.5f, BOSS_SIZE_Y);
    }
}