#pragma once
#include "..\..\..\stdafx.h"
#include "..\Character.h"
namespace Whispers::Entity::Character {

class Player : public Character {
   private:
   public:
    Player(const sf::Vector2f pos, const sf::Vector2f size);
    ~Player();
    void move();
    void update();
};
}  // namespace Whispers::Entity::Character
