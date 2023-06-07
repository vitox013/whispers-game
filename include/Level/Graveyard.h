#pragma once

#include ".\Level.h"

namespace Whispers::Level {
class Graveyard : public Level {
   public:
    Graveyard();
    ~Graveyard();
    void createBackground();
    void createMap();
};
}