#include "..\include\Principal.h"

using namespace Whispers;
using namespace Entity;
using namespace Character;

Principal::Principal()
    : pGraphic(pGraphic->getGraphicManager()),
      pEvent(pEvent->getEventManager()),
      pLevel(nullptr) {
    // std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
    // sf::VideoMode fullscreenMode = modes[0];
    // // sf::RenderWindow window(fullscreenMode, "My window",
    // // sf::Style::Fullscreen);
    // player(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(50.0f, 50.0f))

    createLevel();
    execute();
}

Principal::~Principal() {
    if (pLevel) {
        delete pLevel;
        pLevel = nullptr;
    }
}

void Principal::createLevel() {
    Level::Midnight* pAux = new Level::Midnight(pGraphic);
    if (!pAux) {
        std::cout << "Error on creating level" << std::endl;
        exit(1);
    }
    pLevel = static_cast<Level::Midnight*>(pAux);
    pLevel->createBackground();
    pLevel->createMap();
}

void Principal::execute() {
    while (pGraphic->isWindowOpen()) {
        pEvent->execute();
        pGraphic->clearWindow();
        pLevel->execute();
        pGraphic->showElement();
    }
}
