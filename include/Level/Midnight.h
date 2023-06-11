#pragma once

#include ".\Level.h"

namespace Whispers::Level {
class Midnight : public Level {
   private:
    bool multiplayer;

   public:
    Midnight(const bool multiplayer);
    ~Midnight();
    void createBackground();
    void createMap();
    void randomCreateEntities();
};
}  // namespace Whispers::Level