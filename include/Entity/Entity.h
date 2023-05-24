#pragma once
#include "..\stdafx.h"

namespace Whispers::Entity {
class Entity {
   protected:
    RectangleShape shape;

   public:
    Entity(const Vector2f pos, const Vector2f size);
    virtual ~Entity();
    const RectangleShape getShape() const;
    virtual void update() = 0;
};
}  // namespace Whispers::Entity
