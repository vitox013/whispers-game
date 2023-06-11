#include "..\..\include\State\StateRankingMenu.h"

using namespace Whispers::State;

StateRankingMenu::StateRankingMenu()
    : State(ID::ID::Ranking_Menu),
      rankingMenu()
{
}

StateRankingMenu::~StateRankingMenu()
{
}
void StateRankingMenu::ChangeObserverState()
{
    rankingMenu.ChangeObserverState();
}

void StateRankingMenu::execute()
{
    rankingMenu.Execute();
}