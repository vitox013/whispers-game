#include "..\..\include\Background\Background.h"

using namespace Whispers::Background;

Background::Background()
    : Ente(ID::ID::background),
      lastCamPosition(pGraphic->getCamera().getCenter()) {
    addLayer("assets/background/layer1.png", 0.0f);
}

Background::~Background() {}

void Background::execute() { draw(); }

void Background::draw() {
    Vector2f currentCamPosition = pGraphic->getCamera().getCenter();
    Vector2f camMovement = currentCamPosition - lastCamPosition;

    for (int i = 0; i < layers.size(); i++) {
        Layer* layer = layers[i];
        layer->update(camMovement, currentCamPosition);
        layer->drawLayer(pGraphic->getWindow());
    }

    lastCamPosition = currentCamPosition;
}

void Background::addLayer(const char* path, const float velocity) {
    Layer* layer = new Layer((Vector2f)pGraphic->getWindow()->getSize(),
                             pGraphic->loadTexture(path), velocity);

    layers.push_back(layer);
}