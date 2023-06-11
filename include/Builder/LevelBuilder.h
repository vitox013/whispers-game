#pragma once

#include "..\Level\Midnight.h"
#include "..\Level\Graveyard.h"
namespace Whispers::Builder
{
    class LevelBuilder
    {
    public:
        LevelBuilder();
        ~LevelBuilder();

        Level::Level *createLevel(const ID::ID id, bool multi);

    private:
        Level::Level *createMidnight(bool multi);
        Level::Level *createGraveyard(bool multi);
    };
}