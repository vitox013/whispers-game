#include "..\..\include\Background\Layer.h"

using namespace Whispers::Background;

Layer::Layer(const Vector2f windowSize, Texture texture, const float velocity)
    : windowSize(windowSize),
      texture(texture),
      velocity(velocity),
      dimension(0, 0, 0, 0) {
    dimension.width =
        static_cast<int>(-abs(static_cast<int>(texture.getSize().x)));

    dimension.height = texture.getSize().y;
    // dimension.left = texture.getSize().x;

    back.setSize(windowSize);
    back.setTexture(&this->texture);
    back.setPosition(0.0f, 0.0f);

    // auxBack.setSize(windowSize);
    // auxBack.setTexture(&this->texture);
    // auxBack.setPosition(windowSize.x, 0.0f);
}

Layer::~Layer() {}

void Layer::drawLayer(RenderWindow* window) {
    window->draw(back);
    window->draw(auxBack);
}

void Layer::update(const Vector2f ds, const Vector2f actualCamPosition) {
    // Atualiza a posição do plano de fundo com base no deslocamento da câmera
    // e na posição atual da câmera
    dimension.left -= static_cast<int>(ds.x * velocity);
    dimension.top -= static_cast<int>(ds.y * velocity);

    // Atualiza a posição do plano de fundo para ficar fixa em relação à câmera
    back.setPosition(actualCamPosition.x - windowSize.x / 2,
                     actualCamPosition.y - windowSize.y / 2);
}
