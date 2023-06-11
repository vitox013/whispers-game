#pragma once
#include "..\Menu\MainMenu.h"
#include "State.h"

namespace Whispers::State
{
    class StateMainMenu :public State
    {
    private:
        Menu::MainMenu mainmenu;

    public:
        StateMainMenu();
        ~StateMainMenu();
        void ChangeObserverState();
        void execute();
    };  
}