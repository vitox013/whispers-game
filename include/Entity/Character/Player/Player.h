#pragma once
#include "..\..\..\stdafx.h"
#include "..\Character.h"

#define PLAYER_SPEED 200.0f
#define JUMP_SIZE 0.1f
#define PLAYER_SIZE_X 50.0f
#define PLAYER_SIZE_Y 90.0f
namespace Whispers::Entity::Character {

class Player : public Character {
   private:
    void init();
    bool onFloor;

   public:
    Player(const sf::Vector2f pos, const sf::Vector2f size);
    ~Player();
    void update();
    void jump();
    void canJump();
    void Colission(bool ent);
};
}  // namespace Whispers::Entity::Character
