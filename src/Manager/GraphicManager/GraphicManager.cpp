#include "..\..\..\include\Manager\GraphicManager\GraphicManager.h"

using namespace Whispers;
using namespace Manager;

GraphicManager* GraphicManager::pGraphic = nullptr;

GraphicManager::GraphicManager()
    : window(new sf::RenderWindow(sf::VideoMode(1280, 760), "Whispers")),
      camera(Vector2f(1280 / 2.0f, 760 / 2.0f), Vector2f(1280, 760)) {
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

sf::Font    Whispers::Manager::GraphicManager::LoadFont(const char *FontPath)
{
    sf::Font font;
    if (!font.loadFromFile(FontPath))
    {
        throw("erro ao carregar fonte");
    }
    return font;
}
Texture GraphicManager::loadTexture(const char *path)
{
    Texture texture;
    if (!texture.loadFromFile(path)) {
        std::cout << "Warning: Cannot load texture from " << path << std::endl;
        exit(1);
    }
    return texture;
}

void GraphicManager::clearWindow() { window->clear(); }

void GraphicManager::drawElement(sf::RectangleShape shape) {
    window->draw(shape);
}
void GraphicManager::drawElement(sf::Text text) {
    window->draw(text);
}

void GraphicManager::showElement() { window->display(); }

void GraphicManager::closeWindow() { window->close(); }

const bool GraphicManager::isWindowOpen() { return window->isOpen(); }

void GraphicManager::updateCamera(const Vector2f playerPosition) {
    if (playerPosition.x > 650 && playerPosition.x < 6396.14) {
        camera.setCenter(playerPosition.x, 350.0f);
    } else if (playerPosition.x > 6396.14) {
        camera.setCenter(6396.14, 350.0f);
    } else {
        camera.setCenter(650.0f, 350.0f);
    }
    window->setView(camera);
}

const View GraphicManager::getCamera() { return camera; }

void Whispers::Manager::GraphicManager::ResetWindow()
{
    camera.setCenter(window->getSize().x / 2.0f, window->getSize().y / 2.0f);
    window->setView(camera);
}
