#include "..\..\include\Character\Character.h"

using namespace Whispers;

Character::Character::Character(const Vector2f pos, const Vector2f size)
    : shape(RectangleShape(size)) {
    shape.setPosition(pos);
    shape.setFillColor(Color::Cyan);
    init();
}

Character::Character::~Character() {}

void Character::Character::init() { speed = Vector2f(0.1f, 0.1f); }

const RectangleShape Character::Character::getShape() const { return shape; }