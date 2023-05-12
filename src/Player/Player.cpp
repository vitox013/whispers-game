#include "../../include/Player/Player.h"

using namespace Whispers;
using namespace Character;

Player::Player(const sf::Vector2f pos, const sf::Vector2f size)
    : Character(pos, size) {
    shape.setPosition(pos);
    shape.setFillColor(sf::Color::Cyan);
    init();
}

Player::~Player() {}

void Player::move() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        shape.move(-speed.x, 0.0f);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        shape.move(speed.x, 0.0f);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        shape.move(0.0f, -speed.y);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        shape.move(0.0f, speed.y);
    }
}
