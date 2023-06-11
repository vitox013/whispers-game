#include "..\..\include\State\StateLevelSelectMenu.h"

using namespace Whispers::State;

StateLevelSelectMenu::StateLevelSelectMenu(bool multi)
    : State(ID::ID::Level_Select_Menu),
      levelmenu(multi)
{
}

StateLevelSelectMenu::~StateLevelSelectMenu()
{
}
void StateLevelSelectMenu::ChangeObserverState()
{
    levelmenu.ChangeObserverState();
}

void StateLevelSelectMenu::execute()
{
    levelmenu.Execute();
}