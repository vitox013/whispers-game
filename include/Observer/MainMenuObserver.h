#pragma once
#include "Observer.h"
#include "..\Menu\Button\Button.h"

namespace Whispers
{
    namespace Menu
    {
        class MainMenu;
    }
    namespace Observer
    {
        class MainMenuObserver : public Observer
        {
        private:
            Menu::MainMenu *mainmenu;

        public:
            MainMenuObserver(Menu::MainMenu *mainmenu);
            ~MainMenuObserver();
            void PressedKey(const sf::Keyboard::Key key);
            void ReleasedKey(const sf::Keyboard::Key key);
            void MoveMouse(const sf::Vector2f Mousepos);
            void ReleaseMouseButton(const sf::Mouse::Button mousebtn);
        };
    }
}
