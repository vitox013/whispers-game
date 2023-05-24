#pragma once
#include "..\..\stdafx.h"
#include "..\Entity.h"

namespace Whispers::Entity::Character {

class Character : public Entity {
   protected:
    sf::Vector2f speed;
    void init();

   public:
    Character(const sf::Vector2f pos, const sf::Vector2f tam);
    ~Character();
    const sf::RectangleShape getShape() const;
    virtual void move() = 0;
    virtual void update() = 0;
};
}  // namespace Whispers::Entity::Character
