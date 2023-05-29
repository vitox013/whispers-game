#pragma once
#include <chrono>

#include "..\..\..\stdafx.h"
#include "..\Character.h"

#define PLAYER_SPEED 200.0f
#define JUMP_SIZE 0.4f
#define PLAYER_SIZE_X 50.0f
#define PLAYER_SIZE_Y 70.0f
namespace Whispers::Entity::Character {

class Player : public Character {
   private:
    void init();
    bool onFloor;
    std::chrono::steady_clock::time_point damageStartTime;
    const std::chrono::milliseconds damageDuration{
        600};  // Duração da animação de dano (em milissegundos)
    bool isDamageAnimationActive = false;

   public:
    Player(const sf::Vector2f pos, const sf::Vector2f size);
    ~Player();
    void update();
    void jump();
    void canJump();
    void collision(Entity* other, Vector2f ds = Vector2f(0.0f, 0.0f));
    void updateAnimation();
};
}  // namespace Whispers::Entity::Character
