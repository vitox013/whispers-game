#pragma once
#include "Observer.h"
#include "..\Menu\Button\Button.h"

namespace Whispers
{
    namespace Menu
    {
        class RankingMenu;
    }
    namespace Observer
    {
        class RankingMenuObserver : public Observer
        {
        private:
            Menu::RankingMenu *rankingMenu;

        public:
            RankingMenuObserver(Menu::RankingMenu *rankingMenu);
            ~RankingMenuObserver();
            void PressedKey(const sf::Keyboard::Key key);
            void ReleasedKey(const sf::Keyboard::Key key);
            void MoveMouse(const sf::Vector2f Mousepos);
            void ReleaseMouseButton(const sf::Mouse::Button mousebtn);
            void SaveRank();
        };
    }
}