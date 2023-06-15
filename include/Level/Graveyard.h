#pragma once

#include "./Level.h"

namespace Whispers::Level {
class Graveyard : public Level {
    private:
    bool multiplayer;
   public:
    Graveyard(const bool multiplayer);
    ~Graveyard();
    void createBackground();
    void createMap();
    void randomCreateEntities();
};
}