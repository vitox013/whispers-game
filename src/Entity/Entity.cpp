#include "..\..\include\Entity\Entity.h"

using namespace Whispers;

Entity::Entity::Entity(const Vector2f pos, const Vector2f size, const ID::ID id)
    : Ente(id), shape(RectangleShape(size)), position(pos), size(size) {
    shape.setPosition(pos);
    shape.setFillColor(Color::Cyan);
}

Entity::Entity::~Entity() {}

const RectangleShape Entity::Entity::getShape() const { return shape; }

void Entity::Entity::setPosition(Vector2f pos) {
    shape.setPosition(pos);
    this->position = pos;
}

Vector2f Entity::Entity::getPosition() { return position; }

const Vector2f Entity::Entity::getSize() const { return size; }

void Entity::Entity::draw() { pGraphic->drawElement(shape); }
