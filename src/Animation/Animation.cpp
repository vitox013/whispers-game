#include "..\include\Animation\Animation.h"

using namespace Whispers::Animation;

Animation::Animation(RectangleShape* shape)
    : shape(shape), images(), clock(), currentImage("") {}

Animation::~Animation() {
    map<string, Image*>::iterator it = images.begin();
    while (it != images.end()) {
        if (it->second != nullptr) {
            delete it->second;
            it->second = nullptr;
        }
        it++;
    }
}

void Animation::update(const bool toLeft, string actualImage) {
    if (currentImage != actualImage) {
        if (this->currentImage != "") {
            images[this->currentImage]->reset();
        }

        this->currentImage = actualImage;
    }

    float deltaTime = clock.getElapsedTime().asSeconds();
    clock.restart();

    Image* image = images[this->currentImage];
    Vector2f size = shape->getSize();
    Vector2f scale = image->getScale();
    image->update(toLeft, deltaTime);
    shape->setTextureRect(image->getSize());
    shape->setTexture(image->getTexture());
    shape->setScale(image->getScale());
}

void Animation::addAnimation(const char* path, string nameAnimation,
                             const unsigned int imgCount,
                             const float switchTime, const Vector2f scale) {
    Image* image = new Image(path, imgCount, switchTime, scale);
    images.insert(pair<string, Image*>(nameAnimation, image));
}