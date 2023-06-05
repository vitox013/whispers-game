#pragma once
#include "Observer.h"
#include "..\Entity\Character\Player\Player.h"

namespace Whispers::Observer
{
    class PlayerObserver :public Observer
    {
    private:
        Entity::Character::Player *pPlayer;

    public:
        PlayerObserver(Entity::Character::Player* pPlayeri);
        ~PlayerObserver();
        void PressedKey(const sf::Keyboard::Key key);
        void ReleasedKey(const sf::Keyboard::Key key);
    };    
}