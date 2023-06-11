#include "..\..\..\..\include\Entity\Character\Player\Player.h"

using namespace Whispers::Entity::Character;

Player::Player(const Vector2f pos, const bool isPlayer1, const Vector2f size)
    : Character(pos, size, PLAYER_SPEED, PLAYER_LIFE, false, PLAYER_DAMAGE,
                isPlayer1 ? ID::ID::player : ID::ID::player2),
      onFloor(false),
      player1(isPlayer1) {
    init();
}

Player::~Player() {}

void Player::Player::init() {
    if (player1) {
        animation.addAnimation("assets/character/player/idle.png", "idle", 8,
                               0.15f, Vector2f(6, 6));
        animation.addAnimation("assets/character/player/walk.png", "walk", 8,
                               0.1f, Vector2f(6, 6));
        animation.addAnimation("assets/character/player/jump.png", "jump", 2,
                               0.15f, Vector2f(6, 6));
        animation.addAnimation("assets/character/player/fall.png", "fall", 2,
                               0.15f, Vector2f(6, 6));
        animation.addAnimation("assets/character/player/attack.png", "attack",
                               4, 0.1f, Vector2f(6, 6));
        animation.addAnimation("assets/character/player/hurt.png", "hurt", 4,
                               0.2f, Vector2f(6, 6));
        animation.addAnimation("assets/character/player/death.png", "death", 6,
                               0.2f, Vector2f(6, 6));
        shape.setOrigin(Vector2f(size.x / 2.5f, size.y / 2.5f));
    } else {
        animation.addAnimation("assets/character/player2/idle.png", "idle", 3,
                               0.15f, Vector2f(2.2, 2.1));
        animation.addAnimation("assets/character/player2/walk.png", "walk", 6,
                               0.1f, Vector2f(2.2, 2.1));
        animation.addAnimation("assets/character/player2/jump.png", "jump", 4,
                               0.15f, Vector2f(2.2, 2.1));
        animation.addAnimation("assets/character/player2/fall.png", "fall", 2,
                               0.15f, Vector2f(2.2, 2.1));
        animation.addAnimation("assets/character/player2/attack.png", "attack",
                               6, 0.1f, Vector2f(2.2, 2.1));
        animation.addAnimation("assets/character/player2/hurt.png", "hurt", 3,
                               0.2f, Vector2f(2.2, 2.1));
        animation.addAnimation("assets/character/player2/death.png", "death", 7,
                               0.2f, Vector2f(2.2, 2.1));
        shape.setOrigin(Vector2f(size.x / 2.5f, size.y / 3.1f));
    }
}

void Player::update() {
    updatePosition();
    updateAnimation();
    if (life <= 0) {
        life = 0;
        isAlive = false;
    }
    if (player1) {
        pGraphic->updateCamera(position);
    }
}

void Player::jump() {
    if (onFloor && !takeDamage) {
        speed.y = -sqrt(2.0f * GRAVITY * JUMP_SIZE);
        onFloor = false;
    }
}

void Player::canJump() { onFloor = true; }

void Player::collision(Entity *other, Vector2f ds) {
    Character *character = static_cast<Character *>(other);

    switch (other->getId()) {
        case ID::ID::skeleton:

            if (isAttacking && character->getIsInvincible() == false) {
                character->setTakeDamage(true);
                character->setLife(character->getLife() - damage);
                character->setInvincible(true);
            }

            break;
        case ID::ID::ghost:
            if (isAttacking && character->getIsInvincible() == false) {
                character->setTakeDamage(true);
                character->setLife(character->getLife() - damage);
                character->setInvincible(true);
            }
            break;
        case ID::ID::boss: {
            if (isAttacking && character->getIsInvincible() == false) {
                character->setTakeDamage(true);
                character->setLife(character->getLife() - damage);
                character->setInvincible(true);
            }
            break;
        }
        case ID::ID::Projectile:
            if (!isInvincible) {
                speed.y = -sqrt(1.2f * GRAVITY * JUMP_SIZE);
                onFloor = false;
                takeDamage = true;
                life -= 1;
                setInvincible(true);
                break;
            }
        default:
            break;
    }
}

void Player::updateAnimation() {
    if (isAlive) {
        if (isAttacking) {
            animation.update(faceLeft, "attack");
            if (!isAttackingAnimationActive) {
                attackStartTime = std::chrono::steady_clock::now();
                isAttackingAnimationActive = true;
            } else {
                auto elapsedTime =
                    std::chrono::steady_clock::now() - attackStartTime;
                if (elapsedTime >= attackDuration) {
                    isAttacking = false;
                    size = Vector2f(PLAYER_SIZE_X, PLAYER_SIZE_Y);
                    isAttackingAnimationActive = false;
                }
            }
        } else if (takeDamage) {
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
        } else {
            if (!onFloor && speed.y > 0.0f) {
                animation.update(faceLeft, "fall");
                if (isAttacking) {
                    animation.update(faceLeft, "attack");
                }
            } else if (!onFloor) {
                animation.update(faceLeft, "jump");
            } else if (canWalk && !takeDamage) {
                animation.update(faceLeft, "walk");
            } else if (!takeDamage && !isAttacking) {
                animation.update(faceLeft, "idle");
            }
        }
    } else {
        animation.update(faceLeft, "death");
    }
    auto elapsedTime =
        std::chrono::steady_clock::now() - invincibilityStartTime;
    if (elapsedTime >= invincibilityDuration) {
        // Set invincibility to false
        isInvincible = false;
    }
}

void Player::updatePosition() {
    sf::Time deltaTime = clock.restart();
    float dt = deltaTime.asSeconds();
    Vector2f ds(0.0f, 0.0f);

    if (isAlive) {
        if (canWalk && !takeDamage) {
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

void Player::attack(const bool isAttacking) {
    this->isAttacking = isAttacking;
    size = Vector2f(PLAYER_ATTACK_SIZE_X * 1.2f, PLAYER_SIZE_Y);
}
