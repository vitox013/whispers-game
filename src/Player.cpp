#include "../include/Player.h"

Player::Player(const sf::Vector2f pos, const sf::Vector2f size)
    : shape(sf::RectangleShape(size)) {
    shape.setPosition(pos);
    shape.setFillColor(sf::Color::Cyan);
    init();
}

Player::Player(const sf::RectangleShape shape) : shape(shape) { init(); }

Player::Player() : shape() { init(); }

Player::~Player() {}

void Player::init() { speed = sf::Vector2f(0.1f, 0.1f); }

const sf::RectangleShape Player::getShape() const { return shape; }

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
