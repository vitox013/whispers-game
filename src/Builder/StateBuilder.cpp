#include "..\..\include\Builder\StateBuilder.h"

using namespace Whispers::Builder;
StateBuilder::StateBuilder() {}

StateBuilder::~StateBuilder() {}

Whispers::State::State* StateBuilder::createState(const ID::ID id) {
    if (id == ID::ID::play_midnight) {
        return createStatePlay(id);
    }
    return nullptr;
}

Whispers::State::State* StateBuilder::createStatePlay(const ID::ID id) {
    Level::Level* level = nullptr;
    LevelBuilder levelBuilder;
    level = levelBuilder.createLevel(id);

    Whispers::State::StatePlay* statePlay =
        new Whispers::State::StatePlay(id, level);
    if (!statePlay) {
        std::cout << "Error creating statePlay" << std::endl;
        exit(1);
    }
    return static_cast<State::State*>(statePlay);
}