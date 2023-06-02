#include "..\..\..\include\Entity\Character\Character.h"

using namespace Whispers::Entity;

Character::Character::Character(const Vector2f pos, const Vector2f size,
                                const float speed, const int life,
                                const int damage, const ID::ID ID)
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
      isAlive(true) {}

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

const int Character::Character::getDamage() const { return damage; }

void Character::Character::setSpeed(Vector2f speed) { this->speed = speed; }

const Vector2f Character::Character::getSpeed() const { return speed; }

void Character::Character::setTakeDamage(bool takeDamage) {
    this->takeDamage = takeDamage;
}

void Character::Character::updateAnimation() {
    if (canWalk) {
        animation.update(faceLeft, "walk");
    } else {
        animation.update(faceLeft, "idle");
    }
    // if (takeDamage) {
    //     animation.update(faceLeft, "hurt");
    // }
}
