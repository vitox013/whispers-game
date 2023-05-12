#include "../../include/Character/Character.h"

using namespace Whispers;

Character::Character::Character(const sf::Vector2f pos, const sf::Vector2f size)
    : shape(sf::RectangleShape(size)) {
    shape.setPosition(pos);
    shape.setFillColor(sf::Color::Cyan);
    init();
}

Character::Character::~Character() {}

void Character::Character::init() { speed = sf::Vector2f(0.1f, 0.1f); }

const sf::RectangleShape Character::Character::getShape() const {
    return shape;
}