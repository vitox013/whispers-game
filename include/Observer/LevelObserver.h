#pragma once

#include "Observer.h"
#include "..\Level\Level.h"

namespace Whispers::Observer
{
    class LevelObserver : public Observer
    {
    private:
        Level::Level *level;

    public:
        LevelObserver(Level::Level *level);
        ~LevelObserver();
        void PressedKey(const sf::Keyboard::Key key);
        void ReleasedKey(const sf::Keyboard::Key key);
        void SaveRank();
    };

}