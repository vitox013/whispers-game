#include "../include/Principal.h"

using namespace Whispers;

Principal::Principal()
    : pGraphic(pGraphic->getGraphicManager()),
      player(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(50.0f, 50.0f)) {
    // std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
    // sf::VideoMode fullscreenMode = modes[0];
    // // sf::RenderWindow window(fullscreenMode, "My window",
    // // sf::Style::Fullscreen);
    execute();
}

Principal::~Principal() {}

void Principal::execute() {
    while (pGraphic->isWindowOpen()) {
        sf::Event event;
        while (pGraphic->getWindow()->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                pGraphic->closeWindow();
            }
        }
        pGraphic->clearWindow();
        player.move();
        pGraphic->drawElement(player.getShape());
        pGraphic->showElement();
    }
}