#pragma once
#include "Menu.h"
#include "..\Level\Level.h"

namespace Whispers
{
    namespace Observer{
        class PauseMenuObserver;
    }
    namespace Menu
    {
        class PauseMenu :public Menu
        {
        private:
            Level::Level *level;
            Observer::PauseMenuObserver *pauseMenuObserver;
            sf::RectangleShape DarkBackground;
            sf::RectangleShape DarkPanel;
            void CreateButtons();
            void UpdateBackground();
            void UpdateMenuName();
            void UpdateButtons();

        public:
            PauseMenu(Level::Level *level = nullptr);
            ~PauseMenu();
            void SetLevel(Level::Level *level);
            void ChangeObserverState();
            void Execute();
        };
        
        
        
    }
}