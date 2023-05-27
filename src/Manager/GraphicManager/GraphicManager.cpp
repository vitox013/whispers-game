#include "..\..\..\include\Manager\GraphicManager\GraphicManager.h"

using namespace Whispers;
using namespace Manager;

GraphicManager* GraphicManager::pGraphic = nullptr;

GraphicManager::GraphicManager()
    : window(new sf::RenderWindow(sf::VideoMode(1280, 720), "Whispers")),
      camera(Vector2f(1280 / 2.0f, 720 / 2.0f), Vector2f(1280, 720)) {
    if (window == nullptr) {
        std::cout << "Warning: Cannot create a graphics manager" << std::endl;
        exit(1);
    }
    window->setFramerateLimit(120);
}

GraphicManager::~GraphicManager() {
    if (window) {
        delete (window);
        window = nullptr;
    }
}

GraphicManager* GraphicManager::getGraphicManager() {
    if (pGraphic == nullptr) {
        pGraphic = new GraphicManager();
    }
    return pGraphic;
}

sf::RenderWindow* GraphicManager::getWindow() { return window; }

Texture GraphicManager::loadTexture(const char* path) {
    Texture texture;
    if (!texture.loadFromFile(path)) {
        std::cout << "Warning: Cannot load texture from " << path << std::endl;
        exit(1);
    }
    return texture;
}

void GraphicManager::clearWindow() { window->clear(sf::Color::Black); }

void GraphicManager::drawElement(sf::RectangleShape shape) {
    window->draw(shape);
}

void GraphicManager::showElement() { window->display(); }

void GraphicManager::closeWindow() { window->close(); }

const bool GraphicManager::isWindowOpen() { return window->isOpen(); }

void GraphicManager::updateCamera(const Vector2f playerPosition) {
    camera.setCenter(playerPosition.x, 350.0f);
    window->setView(camera);
}

const View GraphicManager::getCamera() { return camera; }