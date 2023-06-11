#include "..\..\include\Builder\StateBuilder.h"


using namespace Whispers::Builder;
StateBuilder::StateBuilder() {}

StateBuilder::~StateBuilder() {}

Whispers::State::State *StateBuilder::createState(const ID::ID id, bool multi)
{
    if (id == ID::ID::play_midnight)
    {
        return createStatePlay(id, multi);
    } else if (id == ID::ID::play_graveyard) {
        return createStatePlay(id, multi);
    }
    if (id == ID::ID::Main_Menu_state)
    {
        return CreateMainMenu();
    }
    if (id == ID::ID::Pause_menu_state)
    {
        return CreatePauseMenu();
    }
    if (id == ID::ID::Level_Select_Menu)
    {
        return CreateLevelSelectMenu(multi);
    }
    
    return nullptr;
}

Whispers::State::State *StateBuilder::createStatePlay(const ID::ID id, bool multi)
{
    Level::Level *level = nullptr;
    LevelBuilder levelBuilder;
    level = levelBuilder.createLevel(id, multi);

    Whispers::State::StatePlay *statePlay =
        new Whispers::State::StatePlay(id, level);
    if (!statePlay)
    {
        std::cout << "Error creating statePlay" << std::endl;
        exit(1);
    }

    return static_cast<State::State *>(statePlay);
}

Whispers::State::State *Whispers::Builder::StateBuilder::CreateMainMenu()
{
    State::State *state = static_cast<State::State *>(new State::StateMainMenu());
    if (!state)
    {
        std::cout << "Error creating stateMainMenu" << std::endl;
        exit(1);
    }
    return state;
}
Whispers::State::State *Whispers::Builder::StateBuilder::CreateLevelSelectMenu(bool multi)
{
    State::State *state = static_cast<State::State *>(new State::StateLevelSelectMenu(multi));
    if (!state)
    {
        std::cout << "Error creating stateMainMenu" << std::endl;
        exit(1);
    }
    return state;
}
Whispers::State::State *Whispers::Builder::StateBuilder::CreatePauseMenu()
{
    State::State *state = static_cast<State::State *>(new State::StatePause());
    if (!state)
    {
        std::cout << "Error creating statePause" << std::endl;
        exit(1);
    }
    return state;
}
