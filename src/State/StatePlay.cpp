#include "../../include/State/StatePlay.h"

using namespace Whispers::State;


StatePlay::StatePlay(const ID::ID id, Level::Level* level)
    : State(id), level(level) {}

StatePlay::~StatePlay() {}

void StatePlay::execute() { level->execute(); }

Player* StatePlay::getPlayer() { return level->getPlayer(); }

Player* StatePlay::getPlayer2() { return level->getPlayer2(); }

void Whispers::State::StatePlay::ChangeObserverState()
{
    level->ChangeObserverState();
}
Whispers::Level::Level *StatePlay::getLevel()
{
    return level;
}