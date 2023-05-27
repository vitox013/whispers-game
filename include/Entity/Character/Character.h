#pragma once
#include "..\..\stdafx.h"
#include "..\Entity.h"

#define GRAVITY 4.2f
namespace Whispers::Entity::Character {

class Character : public Entity {
   protected:
    sf::Vector2f speed;
    const float maxSpeed;
    int life;
    int damage;
    bool isAttacking;
    bool faceLeft;
    bool canWalk;
    float dt;
    Clock clock;

   public:
    Character(const sf::Vector2f pos, const sf::Vector2f tam, const float speed,
              const ID::ID id);
    ~Character();
    void setSpeed(Vector2f speed);
    const Vector2f getSpeed() const;
    void walk(const bool toLeft);
    void stop();
    void attack(const bool isAttacking);
    void updatePosition();
    // virtual void move() = 0;
    virtual void update() = 0;
    virtual void Colission(Entity* other,
                           Vector2f ds = Vector2f(0.0f, 0.0f)) = 0;
};
}  // namespace Whispers::Entity::Character
