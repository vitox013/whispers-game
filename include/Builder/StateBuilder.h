#pragma once

#include "..\State\State.h"
#include "..\State\StatePlay.h"
#include "..\State\StateMainMenu.h"
#include ".\LevelBuilder.h"

namespace Whispers::Builder {
class StateBuilder {
   private:
    Whispers::State::State* createStatePlay(const ID::ID id);
    State::State *CreateMainMenu();

public:
    StateBuilder();
    ~StateBuilder();

    Whispers::State::State* createState(const ID::ID id);
};
}  // namespace Whispers::Builder