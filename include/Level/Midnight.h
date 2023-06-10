#pragma once

#include ".\Level.h"

namespace Whispers::Level {
class Midnight : public Level {
   public:
    Midnight();
    ~Midnight();
    void createBackground();
    void createMap();
    void randomCreateEntities();
};
}