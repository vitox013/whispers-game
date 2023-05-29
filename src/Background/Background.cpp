#include "..\..\include\Background\Background.h"

using namespace Whispers::Background;

Background::Background(const ID::ID id)
    : Ente(id), lastCamPosition(pGraphic->getCamera().getCenter()), layers() {}

Background::~Background() {
    for (int i = 0; i < layers.size(); i++) {
        Layer* layer = layers.at(i);
        if (layer != nullptr) delete layer;
        layer = nullptr;
    }
    layers.clear();
}

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

void Background::addLayer(const char* path) {
    Layer* layer = new Layer((Vector2f)pGraphic->getWindow()->getSize(),
                             pGraphic->loadTexture(path));

    layers.push_back(layer);
}