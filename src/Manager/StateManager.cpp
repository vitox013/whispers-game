#include "../../include/Manager/StateManager.h"

using namespace Whispers::Manager;

StateManager *StateManager::pStateManager = nullptr;

StateManager::StateManager() : states(), stateBuilder(), multiplayer(false)
{
}

StateManager::~StateManager()
{
    while (!states.empty())
    {
        delete states.top();
        states.top() = nullptr;
        states.pop();
    }

    if (pStateManager != nullptr)
    {
        delete pStateManager;
        pStateManager = nullptr;
    }
}

StateManager *StateManager::getStateManager()
{
    if (pStateManager == nullptr)
    {
        pStateManager = new StateManager();
    }
    return pStateManager;
}

void StateManager::pushState(const ID::ID id, bool multi)
{
    State::State *State = stateBuilder.createState(id, multi);
    if (!State)
    {
        std::cout << "State not found" << std::endl;
        exit(1);
    }
    if (!states.empty())
    {
        DeactivateObserver();
    }

    states.push(State);
}

void StateManager::popState()
{
    if (states.top() != nullptr)
    {
        DeactivateObserver();
        delete states.top();
        states.top() = nullptr;
        states.pop();
    }
    if (!states.empty())
    {
        ActivateObserver();
    }
    else
    {
        GraphicManager::getGraphicManager()->closeWindow();
    }
}

Whispers::State::State *StateManager::getCurrentState() { return states.top(); }

void StateManager::execute()
{
    if (!states.empty())
    {
        states.top()->execute();
    }
}

void Whispers::Manager::StateManager::DeactivateObserver()
{
    State::State *currentstate = getCurrentState();
    currentstate->ChangeObserverState();
}

void Whispers::Manager::StateManager::ActivateObserver()
{
    State::State *currentstate = getCurrentState();
    currentstate->ChangeObserverState();
}
