#include "../../include/Animation/Image.h"

using namespace Whispers;

Animation::Image::Image(const char* path, const unsigned int imgCount,
                        const float switchTime, const Vector2f scale)
    : pGraphic(pGraphic->getGraphicManager()),
      texture(pGraphic->loadTexture(path)),
      size(0, 0, 0, 0),
      scale(scale),
      imgCount(imgCount),
      currentImg(0),
      switchTime(switchTime),
      totalTime(0.0f) {
    size.width = texture.getSize().x / (float)imgCount;
    size.height = texture.getSize().y;
}

Animation::Image::~Image() {}

void Animation::Image::update(const bool toLeft, const float deltaTime) {
    totalTime += deltaTime;

    if (totalTime >= switchTime) {
        totalTime -= switchTime;
        currentImg++;
        if (currentImg >= imgCount) {
            currentImg = 0;
        }
    }

    if (toLeft) {
        size.left = (currentImg + 1) * abs(size.width);
        size.width = -abs(size.width);
    } else {
        size.left = currentImg * size.width;
        size.width = abs(size.width);
    }
}

void Animation::Image::reset() {
    currentImg = 0;
    totalTime = 0.0f;
}

const IntRect Animation::Image::getSize() const { return size; }

const Texture* Animation::Image::getTexture() const { return &texture; }

const Vector2f Animation::Image::getScale() const { return scale; }