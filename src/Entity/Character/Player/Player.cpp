#include "..\..\..\..\include\Entity\Character\Player\Player.h"

using namespace Whispers::Entity::Character;

Player::Player(const Vector2f pos, const Vector2f size)
    : Character(pos, size, PLAYER_SPEED, ID::ID::player), onFloor(false) {
    shape.setFillColor(Color::Cyan);
    init();
}

Player::~Player() {}

void Player::Player::init() {}

void Player::update() { updatePosition(); }

void Player::jump() {
    if (onFloor) {
        speed.y = -sqrt(2.0f * GRAVITY * JUMP_SIZE);
        onFloor = false;
    }
}

void Player::canJump() { onFloor = true; }
void Player::collision(Entity* other, Vector2f ds) {}