#pragma once
#include "Menu.h"
#include "../Background/Background.h"
#include "../Observer/RankingMenuObserver.h"
#define PATH_TEXTURE_MAIN_MENU "assets/background/midnight/midnight.png"
#define BUTTON_SIZE_X 350.0f
#define BUTTON_SIZE_Y 50.0f

namespace Whispers::Menu
{
    class RankingMenu :public Menu
    {
    private:
        Background::Background background;
        Observer::RankingMenuObserver *RankingMenuObserver;
        void CreateBackground();
        void CreateButtons();

    public:
        RankingMenu();
        ~RankingMenu();
        void ChangeObserverState();
        void Execute();
    };
}