#pragma once
#include "Menu.h"
#include "..\Background\Background.h"
#include "..\Observer\LevelSelectMenuObserver.h"
#define PATH_TEXTURE_MAIN_MENU "assets/background/midnight/midnight.png"
#define BUTTON_SIZE_X 350.0f
#define BUTTON_SIZE_Y 50.0f

namespace Whispers::Menu
{
    class LevelSelectMenu :public Menu
    {
    private:
        Background::Background background;
        bool multi;
        Observer::LevelSelectMenuObserver *LevelSelectMenuObserver;
        void CreateBackground();
        void CreateButtons();

    public:
        LevelSelectMenu(bool multi);
        ~LevelSelectMenu();
        void ChangeObserverState();
        void Execute();
        bool GetMulti();
    };
    
 
    
}