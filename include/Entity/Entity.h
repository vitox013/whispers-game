#pragma once
#include "..\Ente.h"
#include "..\stdafx.h"
namespace Whispers::Entity {
class Entity : public Ente {
   protected:
    RectangleShape shape;
    Vector2f position;
    Vector2f size;

   public:
    Entity(const Vector2f pos, const Vector2f size);
    virtual ~Entity();
    const RectangleShape getShape() const;
    void setPosition(Vector2f pos);
    const Vector2f getPosition() const;
    const Vector2f getSize() const;
    virtual void update() = 0;
    void draw();
    virtual void Colission(bool ent) = 0;
};
}  // namespace Whispers::Entity
