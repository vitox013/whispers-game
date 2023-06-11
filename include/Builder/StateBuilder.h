#pragma once

#include "..\State\State.h"
#include "..\State\StatePlay.h"
#include "..\State\StateMainMenu.h"
#include "..\State\StatePause.h"
#include "..\State\StateLevelSelectMenu.h"
#include ".\LevelBuilder.h"

namespace Whispers::Builder
{
    class StateBuilder
    {
    private:
        Whispers::State::State *createStatePlay(const ID::ID id, bool multi);
        State::State *CreateMainMenu();
        State::State *CreatePauseMenu();
        State::State *CreateLevelSelectMenu(bool multi);

    public:
        StateBuilder();
        ~StateBuilder();

        Whispers::State::State *createState(const ID::ID id, bool multi);
    };
} // namespace Whispers::Builder