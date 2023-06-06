#include "..\..\include\Manager\StateManager.h"

using namespace Whispers::Manager;

StateManager* StateManager::pStateManager = nullptr;

StateManager::StateManager() : states(), stateBuilder()
{

}

StateManager::~StateManager() {
    while (!states.empty()) {
        delete states.top();
        states.top() = nullptr;
        states.pop();
    }

    if (pStateManager != nullptr) {
        delete pStateManager;
        pStateManager = nullptr;
    }
}

StateManager* StateManager::getStateManager() {
    if (pStateManager == nullptr) {
        pStateManager = new StateManager();
    }
    return pStateManager;
}

void StateManager::pushState(const ID::ID id) {
    State::State* State = stateBuilder.createState(id);
    if (!State) {
        std::cout << "State not found" << std::endl;
        exit(1);
    }
    states.push(State);
}

void StateManager::popState() {
    if (states.top() != nullptr) {
        delete states.top();
        states.top() = nullptr;
        states.pop();
    }
    if (states.empty()) {
        GraphicManager::getGraphicManager()->closeWindow();
    }
}

Whispers::State::State* StateManager::getCurrentState() { return states.top(); }

void StateManager::execute() {
    if (!states.empty()) {
        states.top()->execute();
    }
}

void Whispers::Manager::StateManager::DeactivateObserver()
{
}

void Whispers::Manager::StateManager::ActivateObserver()
{
}
