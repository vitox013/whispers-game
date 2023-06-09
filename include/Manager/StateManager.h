#pragma once

#include <stack>

#include "../Builder/StateBuilder.h"
#include "./GraphicManager/GraphicManager.h"

namespace Whispers::Manager {
class StateManager {
   private:
    std::stack<State::State*> states;
    Builder::StateBuilder stateBuilder;
    bool multiplayer;
    static StateManager* pStateManager;
    StateManager();
    void DeactivateObserver();
    void ActivateObserver();

public:
    ~StateManager();
    static StateManager* getStateManager();
    void pushState(const ID::ID id, bool multi = false); //adicionar estado
    void popState(); //remover estado
    State::State* getCurrentState();
    void execute();
};
}  // namespace Whispers::Manager