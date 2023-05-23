#include "..\..\..\include\Character\Player\Player.h"

using namespace Whispers;
using namespace Character;

Player::Player(const Vector2f pos, const Vector2f size) : Character(pos, size)
{
    shape.setPosition(pos);
    shape.setFillColor(Color::Cyan);
    init();
}

Player::~Player() {}

void Player::move()
{
    if (Keyboard::isKeyPressed(Keyboard::A))
    {
        shape.move(-speed.x, 0.0f);
    }
    else if (Keyboard::isKeyPressed(Keyboard::D))
    {
        shape.move(speed.x, 0.0f);
    }
    else if (Keyboard::isKeyPressed(Keyboard::W))
    {
        shape.move(0.0f, -speed.y);
    }
    else if (Keyboard::isKeyPressed(Keyboard::S))
    {
        shape.move(0.0f, speed.y);
    }
}

void Player::colission(bool collide)
{
    if (collide == true)
    {
        shape.setFillColor(Color::Magenta);
    }
    else
    {
        shape.setFillColor(Color::Cyan);
    }
    
}