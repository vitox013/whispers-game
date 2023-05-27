#pragma once

#include "..\Ente.h"
#include "..\ID.h"
#include ".\Layer.h"

namespace Whispers::Background {
class Background : public Ente {
   private:
    Vector2f lastCamPosition;
    vector<Layer*> layers;

   public:
    Background();
    ~Background();
    void draw();
    void addLayer(const char* path, const float velocity);
    void execute();
};
}  // namespace Whispers::Background