#pragma once
#include "../Ente.h"
#include "../stdafx.h"
namespace Whispers::Entity {
class Entity : public Ente {
   protected:
    RectangleShape shape;
    Vector2f position;
    Vector2f size;

   public:
    Entity(const Vector2f pos, const Vector2f size, const ID::ID id);
    virtual ~Entity();
    const RectangleShape getShape() const;
    void setPosition(Vector2f pos);
    Vector2f getPosition();
    const Vector2f getSize() const;
    virtual void update() = 0;
    void draw();
    virtual void collision(Entity* other,
                           Vector2f ds = Vector2f(0.0f, 0.0f)) = 0;
};
}  // namespace Whispers::Entity
