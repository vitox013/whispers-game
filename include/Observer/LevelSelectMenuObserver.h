#pragma once
#include "Observer.h"
#include "..\Menu\Button\Button.h"

namespace Whispers
{
    namespace Menu
    {
        class LevelSelectMenu;
    }
    namespace Observer
    {
        class LevelSelectMenuObserver : public Observer
        {
        private:
            Menu::LevelSelectMenu *levelSelectMenu;

        public:
            LevelSelectMenuObserver(Menu::LevelSelectMenu *mainmenu);
            ~LevelSelectMenuObserver();
            void PressedKey(const sf::Keyboard::Key key);
            void ReleasedKey(const sf::Keyboard::Key key);
            void MoveMouse(const sf::Vector2f Mousepos);
            void ReleaseMouseButton(const sf::Mouse::Button mousebtn);
            void SaveRank();
        };
    }
}