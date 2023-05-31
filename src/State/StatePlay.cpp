#include "..\..\include\State\StatePlay.h"

using namespace Whispers::State;

StatePlay::StatePlay(const ID::ID id, Level::Level* level)
    : State(id), level(level) {}

StatePlay::~StatePlay() {}

void StatePlay::execute() { level->execute(); }

Player* StatePlay::getPlayer() { return level->getPlayer(); }