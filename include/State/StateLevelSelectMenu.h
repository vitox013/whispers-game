#pragma once
#include "..\Menu\LevelSelectMenu.h"
#include "State.h"

namespace Whispers::State
{
    class StateLevelSelectMenu :public State
    {
    private:
        Menu::LevelSelectMenu levelmenu;

    public:
        StateLevelSelectMenu(bool multi);
        ~StateLevelSelectMenu();
        void ChangeObserverState();
        void execute();
    };  
}