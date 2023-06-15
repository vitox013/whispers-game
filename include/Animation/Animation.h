#pragma once

#include <map>

#include "./Image.h"

namespace Whispers::Animation {
class Animation {
   private:
    RectangleShape* shape;
    std::map<string, Image*> images;
    Clock clock;
    string currentImage;

   public:
    Animation(RectangleShape* shape);
    ~Animation();
    void update(const bool toLeft, string actualImage);
    void addAnimation(const char* path, string nameAnimation,
                      const unsigned int imgCount, const float switchTime,
                      const Vector2f scale);
};

}  // namespace Whispers::Animation