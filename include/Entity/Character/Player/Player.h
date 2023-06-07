#pragma once
#include <chrono>

#include "..\..\..\stdafx.h"
#include "..\Character.h"

#define PLAYER_SPEED 200.0f
#define JUMP_SIZE 0.4f
#define PLAYER_SIZE_X 50.0f
#define PLAYER_SIZE_Y 70.0f
#define PLAYER_LIFE 3
#define PLAYER_DAMAGE 2

namespace Whispers::Entity::Character {

class Player : public Character {
   private:
    void init();
    bool onFloor;
    std::chrono::steady_clock::time_point damageStartTime;
    std::chrono::steady_clock::time_point attackStartTime;
    std::chrono::steady_clock::time_point deathStartTime;
    const std::chrono::milliseconds attackDuration{
        300};  // Duração da animação de ataque (em milissegundos)
    const std::chrono::milliseconds damageDuration{
        600};  // Duração da animação de dano (em milissegundos)
    const std::chrono::milliseconds deathDuration{
       300};  // Duração da animação de morte (em milissegundos)
    bool isDamageAnimationActive = false;
    bool isAttackingAnimationActive = false;
    bool isDeadAnimationActive = false;
    std::chrono::steady_clock::time_point invincibilityStartTime;
    bool isInvincible = false;
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
    const bool getIsInvincible() const;
    void setInvincible(const bool isInvincible);
};
}  // namespace Whispers::Entity::Character
