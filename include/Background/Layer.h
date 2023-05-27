#pragma once
#include "..\stdafx.h"

namespace Whispers::Background {
class Layer {
   private:
    const Vector2f windowSize;
    IntRect dimension;
    const float velocity;
    Texture texture;
    RectangleShape back;

    void changeTexture();

   public:
    Layer(Vector2f windowSize, Texture texture, const float velocity);
    ~Layer();
    void drawLayer(RenderWindow* window);
    void update(const Vector2f ds, const Vector2f actualCamPosition);
};
}  // namespace Whispers::Background