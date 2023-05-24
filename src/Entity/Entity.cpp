#include "..\..\include\Entity\Entity.h"

using namespace Whispers;

Entity::Entity::Entity(const Vector2f pos, const Vector2f size)
    : shape(RectangleShape(size)) {}

Entity::Entity::~Entity() {}

const RectangleShape Entity::Entity::getShape() const { return shape; }
