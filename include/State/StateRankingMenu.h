#pragma once
#include "../Menu/RankingMenu.h"
#include "State.h"

namespace Whispers::State
{
    class StateRankingMenu :public State
    {
    private:
        Menu::RankingMenu rankingMenu;

    public:
        StateRankingMenu();
        ~StateRankingMenu();
        void ChangeObserverState();
        void execute();
    };  
}