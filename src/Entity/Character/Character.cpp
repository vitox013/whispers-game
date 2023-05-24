#include "..\..\..\include\Entity\Character\Character.h"

using namespace Whispers::Entity;

Character::Character::Character(const Vector2f pos, const Vector2f size)
    : Entity(pos, size) {
    shape.setPosition(pos);
    shape.setFillColor(Color::Cyan);
    init();
}

Character::Character::~Character() {}

void Character::Character::init() { speed = Vector2f(0.1f, 0.1f); }

const RectangleShape Character::Character::getShape() const { return shape; }