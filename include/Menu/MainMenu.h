#pragma once
#include "Menu.h"
#include "../Background/Background.h"
#include "../Observer/MainMenuObserver.h"
#define PATH_TEXTURE_MAIN_MENU "assets/background/midnight/midnight.png"
#define BUTTON_SIZE_X 350.0f
#define BUTTON_SIZE_Y 50.0f

namespace Whispers::Menu
{
    class MainMenu :public Menu
    {
    private:
        Background::Background background;
        Observer::MainMenuObserver *mainmenuObserver;
        void CreateBackground();
        void CreateButtons();

    public:
        MainMenu();
        ~MainMenu();
        void ChangeObserverState();
        void Execute();
    };
}