#pragma once

#include <stack>

#include "..\Builder\StateBuilder.h"
#include ".\GraphicManager\GraphicManager.h"

namespace Whispers::Manager {
class StateManager {
   private:
    std::stack<State::State*> states;
    Builder::StateBuilder stateBuilder;

    static StateManager* pStateManager;
    StateManager();

   public:
    ~StateManager();
    static StateManager* getStateManager();
    void pushState(const ID::ID id);
    void popState();
    State::State* getCurrentState();
    void execute();
};
}  // namespace Whispers::Manager