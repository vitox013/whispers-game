#pragma once

#include "..\Manager\GraphicManager\GraphicManager.h"
#include "..\stdafx.h"

namespace Whispers::Animation {
class Image {
   private:
    Manager::GraphicManager* pGraphic;
    Texture texture;
    IntRect size;
    const Vector2f scale;
    const unsigned int imgCount;
    unsigned int currentImg;
    const float switchTime;
    float totalTime;

   public:
    Image(const char* path, const unsigned int imgCount, const float switchTime,
          const Vector2f scale);
    ~Image();
    void update(const bool toLeft, const float deltaTime);
    void reset();
    const IntRect getSize() const;
    const Texture* getTexture() const;
    const Vector2f getScale() const;
};

}  // namespace Whispers::Animation