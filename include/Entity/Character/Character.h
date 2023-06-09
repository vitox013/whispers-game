#pragma once
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
    bool takeDamage;
    bool idle;
    bool isAlive;
    float dt;
    Clock clock;
    virtual void updateAnimation();

   public:
    Character(const sf::Vector2f pos, const sf::Vector2f tam, const float speed,
              const int life, const int damage, const ID::ID id);
    ~Character();
    void setSpeed(Vector2f speed);
    const Vector2f getSpeed() const;
    void walk(const bool toLeft);
    void stop();
    virtual void attack(const bool isAttacking);
    void setTakeDamage(bool takeDamage);
    const bool getIsAlive() const;
    void updatePosition();
    const int getDamage() const;
    // virtual void move() = 0;
    virtual void update() = 0;

    virtual void collision(Entity* other,
                           Vector2f ds = Vector2f(0.0f, 0.0f)) = 0;
};
}  // namespace Whispers::Entity::Character
