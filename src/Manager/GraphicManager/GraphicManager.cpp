#include "../../../include/Manager/GraphicManager/GraphicManager.h"

using namespace Whispers;
using namespace Manager;

GraphicManager* GraphicManager::pGM = nullptr;

GraphicManager::GraphicManager()
    : window(new sf::RenderWindow(sf::VideoMode(800, 600), "Whispers")) {
    if (window == nullptr) {
        std::cout << "Warning: Cannot create a graphics manager" << std::endl;
        exit(1);
    }
}

GraphicManager::~GraphicManager() {
    if (window) {
        delete window;
        window = nullptr;
    }
}

GraphicManager* GraphicManager::getGraphicManager() {
    if (pGM == nullptr) {
        return new GraphicManager();
    }
    return pGM;
}

sf::RenderWindow* GraphicManager::getWindow() { return window; }

void GraphicManager::clearWindow() { window->clear(sf::Color::Black); }

void GraphicManager::drawElement(sf::RectangleShape shape) {
    window->draw(shape);
}

void GraphicManager::showElement() { window->display(); }

void GraphicManager::closeWindow() { window->close(); }

const bool GraphicManager::isWindowOpen() { return window->isOpen(); }