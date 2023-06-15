#include "../../../include/Entity/Character/Character.h"

using namespace Whispers::Entity;

Character::Character::Character(const Vector2f pos, const Vector2f size,
                                const float speed, const int life,
                                const bool canFly, const int damage,
                                const ID::ID ID)
    : Entity(pos, size, ID),
      canWalk(false),
      faceLeft(false),
      clock(),
      dt(0.0f),
      speed(Vector2f(speed, 0.0f)),
      maxSpeed(speed),
      isAttacking(false),
      animation(&shape),
      takeDamage(false),
      life(life),
      damage(damage),
      isAlive(true),
      canFly(canFly) {}

Character::Character::~Character() {}

void Character::Character::walk(const bool toLeft) {
    // isAttacking = false;
    canWalk = true;
    if (!takeDamage) {
        this->faceLeft = toLeft;
    }
}

void Character::Character::stop() { canWalk = false; }

void Character::Character::attack(const bool isAttacking) {
    canWalk = false;
    this->isAttacking = isAttacking;
}

void Character::Character::setLife(int l) { life = l; }

void Character::Character::setInvincible(const bool invincibility) {
    invincibilityStartTime = std::chrono::steady_clock::now();
    isInvincible = invincibility;
}

const bool Character::Character::getIsInvincible() const {
    return isInvincible;
}

int Character::Character::getLife() const { return life; }

void Character::Character::updatePosition() {
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
            ds.x = speed.x * dt * 1.2f;
        } else {
            ds.x = -speed.x * dt * 1.2f;
        }
    }

    if (!canFly) {
        speed.y += GRAVITY * dt;
        ds.y = speed.y * GRAVITY;
    } else {
        ds.y += speed.y * dt;
    }

    setPosition(Vector2f(position.x + ds.x, position.y + ds.y));

    speed.x = maxSpeed;

    draw();
}

const int Character::Character::getDamage() const { return damage; }

const bool Character::Character::getFaceLeft() const { return faceLeft; }

void Character::Character::setSpeed(Vector2f sp) { speed = sp; }

const Vector2f Character::Character::getSpeed() const { return speed; }

const bool Character::Character::getIsAlive() const { return isAlive; }

const bool Character::Character::getIsAttacking() const { return isAttacking; }

void Character::Character::setTakeDamage(bool takeDamage) {
    this->takeDamage = takeDamage;
}

void Character::Character::updateAnimation() {
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
    }else if (canWalk) {
        animation.update(faceLeft, "walk");
    } else {
        animation.update(faceLeft, "idle");
    }
    auto elapsedTime =
        std::chrono::steady_clock::now() - invincibilityStartTime;
    if (elapsedTime >= invincibilityDuration) {
        // Set invincibility to false
        isInvincible = false;
    }
}
