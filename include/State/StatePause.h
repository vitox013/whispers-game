#pragma once 
#include "..\Menu\PauseMenu.h"
#include "State.h"
namespace Whispers
{
    namespace Manager{
        class StateManager;
    }
    namespace State
    {
        class StatePlay;

        class StatePause :public State
        {
        private:
            Menu::PauseMenu pausemenu;
            StatePlay *stateplay;
            static Manager::StateManager *pStateMa;

        public:
            StatePause();
            ~StatePause();
            void ChangeObserverState();
            void execute();
        };
        
        
        
    }
}