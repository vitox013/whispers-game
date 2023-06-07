#include "..\include\Principal.h"

using namespace Whispers;
using namespace Entity;
using namespace Character;

Principal::Principal()
    : pGraphic(pGraphic->getGraphicManager()),
      pEvent(pEvent->getEventManager()),
      pState(pState->getStateManager()) {
    // std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
    // sf::VideoMode fullscreenMode = modes[0];
    // // sf::RenderWindow window(fullscreenMode, "My window",
    // // sf::Style::Fullscreen);
    // player(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(50.0f, 50.0f))
    if (pGraphic == nullptr) {
        std::cout << "pGraphic is null" << std::endl;
        exit(1);
    }
    if (pEvent == nullptr) {
        std::cout << "pEvent is null" << std::endl;
        exit(1);
    }
    if (pState == nullptr) {
        std::cout << "pState is null" << std::endl;
        exit(1);
    }

    init();
}

Principal::~Principal() {}

void Principal::init() { pState->pushState(ID::ID::Main_Menu_state); }

void Principal::execute() {
    while (pGraphic->isWindowOpen()) {
        pEvent->execute();
        pGraphic->clearWindow();
        pState->execute();
        pGraphic->showElement();
    }
}
