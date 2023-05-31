#pragma once

#include "..\Level\Midnight.h"

namespace Whispers::Builder {
class LevelBuilder {
   public:
    LevelBuilder();
    ~LevelBuilder();

    Level::Level* createLevel(const ID::ID id);

   private:
    Level::Level* createMidnight();
};
}  // namespace Whispers::Builder