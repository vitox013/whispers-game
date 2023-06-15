#pragma once

#include "../Ente.h"
#include "../ID.h"
#include "./Layer.h"

namespace Whispers::Background {
class Background : public Ente {
   private:
    Vector2f lastCamPosition;
    vector<Layer*> layers;

   public:
    Background(const ID::ID id);
    ~Background();
    void draw();
    void addLayer(const char* path);
    void execute();
};
}  // namespace Whispers::Background