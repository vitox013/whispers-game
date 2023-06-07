#include "..\..\..\..\include\Entity\Character\Player\Player.h"

using namespace Whispers::Entity::Character;

Player::Player(const Vector2f pos, const Vector2f size)
    : Character(pos, size, PLAYER_SPEED, PLAYER_LIFE, PLAYER_DAMAGE,
                ID::ID::player),
      onFloor(false) {
    init();
}

Player::~Player() {}

void Player::Player::init() {
    animation.addAnimation("assets/character/player/idle.png", "idle", 8, 0.15f,
                           Vector2f(6, 6));
    animation.addAnimation("assets/character/player/walk.png", "walk", 8, 0.1f,
                           Vector2f(6, 6));
    animation.addAnimation("assets/character/player/jump.png", "jump", 2, 0.15f,
                           Vector2f(6, 6));
    animation.addAnimation("assets/character/player/fall.png", "fall", 2, 0.15f,
                           Vector2f(6, 6));
    animation.addAnimation("assets/character/player/attack.png", "attack", 4,
                           0.1f, Vector2f(6, 6));
    animation.addAnimation("assets/character/player/hurt.png", "hurt", 4, 0.2f,
                           Vector2f(6, 6));
    animation.addAnimation("assets/character/player/death.png", "death", 6,
                           0.2f, Vector2f(6, 6));
    shape.setOrigin(Vector2f(size.x / 2.5f, size.y / 2.5f));
}

void Player::update() {
    updatePosition();
    updateAnimation();
    pGraphic->updateCamera(position);
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
    if (!isInvincible) {
        switch (other->getId()) {
            case ID::ID::skeleton:

                speed.y = -sqrt(1.2f * GRAVITY * JUMP_SIZE);
                // Player is not currently taking damage and either the player
                // or the skeleton is in the air
                takeDamage = true;
                life -= character->getDamage();
                if (life <= 0) {
                    life = 0;
                    isAlive = false;
                }

                break;
            case ID::ID::Projectile:
                cout << "Player life: " << life << endl;
                speed.y = -sqrt(1.2f * GRAVITY * JUMP_SIZE);
                onFloor = false;
                takeDamage = true;
                life -= 1;

                break;
            default:
                break;
        }

        if (life <= 0) {
            life = 0;
            isAlive = false;
        } else {
            setInvincible(true);
        }
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

    draw();
}

void Player::attack(const bool isAttacking) { this->isAttacking = isAttacking; }

const bool Player::getIsInvincible() const { return isInvincible; }

void Player::setInvincible(const bool isInvincible) {
    invincibilityStartTime = std::chrono::steady_clock::now();
    this->isInvincible = isInvincible;
}