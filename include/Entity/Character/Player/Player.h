#pragma once


#include "..\..\..\stdafx.h"
#include "..\Character.h"

#define PLAYER_SPEED 200.0f
#define JUMP_SIZE 0.4f
#define PLAYER_SIZE_X 50.0f
#define PLAYER_SIZE_Y 70.0f
#define PLAYER_ATTACK_SIZE_X 100.0f
#define PLAYER_LIFE 10
#define PLAYER_DAMAGE 2

namespace Whispers::Entity::Character {

class Player : public Character {
   private:
    void init();
    bool onFloor;
    
    std::chrono::steady_clock::time_point deathStartTime;
    

    const std::chrono::milliseconds deathDuration{
        300};  // Duração da animação de morte (em milissegundos)
    
    bool isDeadAnimationActive = false;
    const std::chrono::milliseconds invincibilityDuration{3000};

   public:
    Player(const sf::Vector2f pos, const sf::Vector2f size);
    ~Player();
    void update();
    void jump();
    void canJump();
    void collision(Entity *other, Vector2f ds = Vector2f(0.0f, 0.0f));
    void updateAnimation();
    void updatePosition();
    void attack(const bool isAttacking);
};
}  // namespace Whispers::Entity::Character
