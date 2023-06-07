#pragma once

#include "..\Level\Midnight.h"
#include "..\Level\Graveyard.h"
namespace Whispers::Builder {
class LevelBuilder {
   public:
    LevelBuilder();
    ~LevelBuilder();

    Level::Level* createLevel(const ID::ID id);

   private:
    Level::Level* createMidnight();
    Level::Level* createGraveyard();
};
}  // namespace Whispers::Builder