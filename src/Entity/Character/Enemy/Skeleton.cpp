#include "..\..\..\..\include\Entity\Character\Enemy\Skeleton.h"

using namespace Whispers::Entity::Character::Enemy;

Skeleton::Skeleton(const sf::Vector2f pos, Player* player)
    : Enemy(pos, sf::Vector2f(SKELETON_SIZE_X, SKELETON_SIZE_Y), SKELETON_LIFE,
            SKELETON_DAMAGE, player, ID::ID::skeleton) {
    init();
}

Skeleton::~Skeleton() {}

void Skeleton::init() {
    animation.addAnimation("assets/character/enemy/skeleton/idle.png", "idle",
                           4, 0.3f, sf::Vector2f(4.0, 4.0));
    animation.addAnimation("assets/character/enemy/skeleton/walk.png", "walk",
                           4, 0.2f, sf::Vector2f(4.0, 4.0));
    shape.setOrigin(sf::Vector2f(size.x / 2.5f, size.y / 3.0f));
}
