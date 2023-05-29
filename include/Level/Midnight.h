#pragma once

#include ".\Level.h"

namespace Whispers::Level {
class Midnight : public Level {
   public:
    Midnight(Manager::GraphicManager* pGraphic);
    ~Midnight();
    void createBackground();
    void createMap();
};
}