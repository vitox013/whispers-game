#pragma once
#include <chrono>

#include "..\..\Animation\Animation.h"
#include "..\..\stdafx.h"
#include "..\Entity.h"

#define GRAVITY 4.2f
namespace Whispers::Entity::Character {

class Character : public Entity {
   protected:
    sf::Vector2f speed;
    Animation::Animation animation;
    const float maxSpeed;
    int life;
    int damage;
    bool isAttacking;
    bool faceLeft;
    bool canWalk;
    bool canFly;
    bool takeDamage;
    bool idle;
    bool isAlive;
    float dt;
    Clock clock;
    std::chrono::steady_clock::time_point damageStartTime;
    std::chrono::steady_clock::time_point attackStartTime;
    std::chrono::steady_clock::time_point invincibilityStartTime;
    const std::chrono::milliseconds damageDuration{600};
    const std::chrono::milliseconds attackDuration{300};
    const std::chrono::milliseconds invincibilityDuration{1000};
    bool isDamageAnimationActive = false;
    bool isAttackingAnimationActive = false;
    bool isInvincible = false;
    virtual void updateAnimation();

   public:
    Character(const sf::Vector2f pos, const sf::Vector2f tam, const float speed,
              const int life, const bool canFly, const int damage,
              const ID::ID id);
    ~Character();
    void setSpeed(Vector2f speed);
    const Vector2f getSpeed() const;
    void walk(const bool toLeft);
    void stop();
    virtual void attack(const bool isAttacking);
    void setLife(int life);
    void setInvincible(const bool invincibility);
    const bool getIsInvincible() const;
    int getLife() const;
    void setTakeDamage(bool takeDamage);
    const bool getIsAlive() const;
    const bool getIsAttacking() const;
    virtual void updatePosition();
    const int getDamage() const;
    const bool getFaceLeft() const;
    virtual void update() = 0;
    virtual void collision(Entity* other,
                           Vector2f ds = Vector2f(0.0f, 0.0f)) = 0;
};
}  // namespace Whispers::Entity::Character
