#include "..\..\include\Builder\StateBuilder.h"


using namespace Whispers::Builder;
StateBuilder::StateBuilder() {}

StateBuilder::~StateBuilder() {}

Whispers::State::State *StateBuilder::createState(const ID::ID id)
{
    if (id == ID::ID::play_midnight)
    {
        return createStatePlay(id);
    } else if (id == ID::ID::play_graveyard) {
        return createStatePlay(id);
    }
    if (id == ID::ID::Main_Menu_state)
    {
        return CreateMainMenu();
    }
    
    return nullptr;
}

Whispers::State::State *StateBuilder::createStatePlay(const ID::ID id)
{
    Level::Level *level = nullptr;
    LevelBuilder levelBuilder;
    level = levelBuilder.createLevel(id);

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
        std::cout << "Error creating statePlay" << std::endl;
        exit(1);
    }
    return state;
}
