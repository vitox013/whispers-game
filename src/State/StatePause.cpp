#include "../../include/State/StatePause.h"
#include "../../include/Manager/StateManager.h"

using namespace Whispers::State;
using namespace Whispers;

Manager::StateManager *StatePause::pStateMa = Manager::StateManager::getStateManager();

StatePause::StatePause()
    : State(ID::ID::Pause_menu_state),
    stateplay(nullptr),
    pausemenu()
{
    State *currentState = pStateMa->getCurrentState();
    if (currentState->getId() != ID::ID::play_midnight && currentState->getId() != ID::ID::play_graveyard)
    {
        std::cout << "Estado atual nao e uma fase" << std::endl;
        exit(2);
    }
    stateplay = static_cast<StatePlay *>(currentState);
    pausemenu.SetLevel(stateplay->getLevel());
}

StatePause::~StatePause()
{
}

void StatePause::ChangeObserverState()
{
    pausemenu.ChangeObserverState();
}

void StatePause::execute()
{
    pausemenu.Execute();
}
