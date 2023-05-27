#include "..\..\..\..\include\Entity\Character\Player\Player.h"

using namespace Whispers::Entity::Character;

Player::Player(const Vector2f pos, const Vector2f size)
    : Character(pos, size, PLAYER_SPEED, ID::ID::player), onFloor(false) {
    init();
}

Player::~Player() {}

void Player::Player::init() {
    animation.addAnimation("assets/character/player/idle.png", "idle", 4, 1.0f,
                           Vector2f(2, 2));
    animation.addAnimation("assets/character/player/walk.png", "walk", 8, 0.1f,
                           Vector2f(2, 2));
    animation.addAnimation("assets/character/player/jump.png", "jump", 1, 0.15f,
                           Vector2f(2, 2));
    animation.addAnimation("assets/character/player/fall.png", "fall", 2, 0.15f,
                           Vector2f(2, 2));
    animation.addAnimation("assets/character/player/attack.png", "attack", 1,
                           0.1f, Vector2f(2, 2));
    shape.setOrigin(Vector2f(size.x / 4.0f, size.y / 2.2f));
}

void Player::update() {
    updatePosition();
    updateAnimation();
    pGraphic->updateCamera(position);
}

void Player::jump() {
    if (onFloor) {
        speed.y = -sqrt(2.0f * GRAVITY * JUMP_SIZE);
        onFloor = false;
    }
}

void Player::canJump() { onFloor = true; }
void Player::collision(Entity* other, Vector2f ds) {}

void Player::updateAnimation() {
    if (!onFloor && speed.y > 0.0f) {
        animation.update(faceLeft, "fall");
    } else if (!onFloor) {
        animation.update(faceLeft, "jump");
    } else if (isAttacking) {
        animation.update(faceLeft, "attack");
    } else if (canWalk) {
        animation.update(faceLeft, "walk");
    } else {
        animation.update(faceLeft, "idle");
    }
}