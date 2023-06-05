#pragma once
#include "..\include\Observer\PlayerObserver.h"
using namespace Whispers::Observer;

PlayerObserver::PlayerObserver(Entity::Character::Player *pPlayeri)
    :Observer::Observer(), pPlayer(pPlayeri)
{
}

PlayerObserver::~PlayerObserver()
{
}
void Whispers::Observer::PlayerObserver::PressedKey(const sf::Keyboard::Key key)
{
    if (key == Keyboard::A)
    {
        pPlayer->walk(true);
    }
    else if (key == Keyboard::D)
    {
        pPlayer->walk(false);
    }
    else if (Keyboard::isKeyPressed(Keyboard::LShift))
    {
        pPlayer->attack(true);
    }
    if (key == Keyboard::Space)
    {
        pPlayer->jump();
    }
}

void Whispers::Observer::PlayerObserver::ReleasedKey(const sf::Keyboard::Key key)
{
    if (key == Keyboard::A)
    {
         pPlayer->stop();
    }
    else if (key == Keyboard::D)
    {
         pPlayer->stop();
    }
}
