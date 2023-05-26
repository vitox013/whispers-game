#include "..\..\..\include\Entity\Character\Character.h"

using namespace Whispers::Entity;

Character::Character::Character(const Vector2f pos, const Vector2f size,
                                const float speed)
    : Entity(pos, size),
      canWalk(false),
      faceLeft(false),
      clock(),
      dt(0.0f),
      speed(Vector2f(speed, 0.0f)),
      maxSpeed(speed),
      isAttacking(false) {}

Character::Character::~Character() {}

void Character::Character::walk(const bool toLeft) {
    isAttacking = false;
    canWalk = true;
    this->faceLeft = toLeft;
}

void Character::Character::stop() { canWalk = false; }

void Character::Character::attack(const bool isAttacking) {
    canWalk = false;
    this->isAttacking = isAttacking;
}

void Character::Character::updatePosition() {
    dt = clock.getElapsedTime().asSeconds();
    clock.restart();
    Vector2f ds(0.0f, 0.0f);

    if (canWalk) {
        ds.x = speed.x * dt;
        if (faceLeft) {
            ds.x *= -1;
        }
    }

    speed.y += GRAVITY * dt;
    ds.y = speed.y * GRAVITY;

    setPosition(Vector2f(position.x + ds.x, position.y + ds.y));

    speed.x = maxSpeed;

    draw();
}

void Character::Character::setSpeed(Vector2f speed) { this->speed = speed; }

const Vector2f Character::Character::getSpeed() const { return speed; }