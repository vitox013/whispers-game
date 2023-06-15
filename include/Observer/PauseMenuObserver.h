#pragma once
#include "Observer.h"
#include "../Menu/PauseMenu.h"

namespace Whispers::Observer
{
    class PauseMenuObserver : public Observer
    {
    private:
        Menu::PauseMenu *pauseMenu;

    public:
        PauseMenuObserver(Menu::PauseMenu* pausemenu);
        ~PauseMenuObserver();
        void PressedKey(const sf::Keyboard::Key key);
        void ReleasedKey(const sf::Keyboard::Key key);
        void SaveRank();
    };

}