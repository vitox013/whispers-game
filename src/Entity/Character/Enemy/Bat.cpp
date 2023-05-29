#include "..\..\..\..\include\Entity\Character\Enemy\Bat.h"

using namespace Whispers::Entity::Character::Enemy;

Bat::Bat(const sf::Vector2f pos, Player* player)
    : Enemy(pos, sf::Vector2f(BAT_SIZE_X, BAT_SIZE_Y), player, ID::ID::bat) {
    init();
}

Bat::~Bat() {}

void Bat::init() {
    animation.addAnimation("assets/character/enemy/bat/idle.png", "idle", 4,
                           0.3f, sf::Vector2f(1.0, 1.0));
    animation.addAnimation("assets/character/enemy/bat/walk.png", "walk", 4,
                           0.2f, sf::Vector2f(1.0, 1.0));
    shape.setOrigin(sf::Vector2f(size.x / 2.5f, size.y / 3.0f));
}