#include "../../include/State/StateMainMenu.h"

using namespace Whispers::State;

StateMainMenu::StateMainMenu()
    : State(ID::ID::Main_Menu_state),
      mainmenu()
{
}

StateMainMenu::~StateMainMenu()
{
}
void Whispers::State::StateMainMenu::ChangeObserverState()
{
    mainmenu.ChangeObserverState();
}

void Whispers::State::StateMainMenu::execute()
{
    mainmenu.Execute();
}
