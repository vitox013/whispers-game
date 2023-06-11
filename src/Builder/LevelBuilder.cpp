#include "..\..\include\Builder\LevelBuilder.h"

using namespace Whispers::Builder;
using namespace Whispers::Level;

LevelBuilder::LevelBuilder() {}

LevelBuilder::~LevelBuilder() {}

Level* LevelBuilder::createLevel(const ID::ID id) {
    Level::Level* level = nullptr;

    // Verificar o ID do level e criar o level correspondente
    switch (id) {
        case (ID::ID::play_midnight): {
            level = createMidnight();
        } break;
        case (ID::ID::play_graveyard): {
            level = createGraveyard();
        } break;
        default: {
            std::cout << "Error creating level" << std::endl;
            exit(1);
        } break;
    }
    level->createBackground();
    level->createMap();
    return level;
}

Level* LevelBuilder::createMidnight() {
    Level::Level* midnight = static_cast<Level::Level*>(new Midnight(true));
    if (!midnight) {
        std::cout << "Error creating midnight" << std::endl;
        exit(1);
    }
    return midnight;
}

Level* LevelBuilder::createGraveyard() {
    Level::Level* graveyard = static_cast<Level::Level*>(new Graveyard(false));
    if (!graveyard) {
        std::cout << "Error creating graveyard" << std::endl;
        exit(1);
    }
    return graveyard;
}