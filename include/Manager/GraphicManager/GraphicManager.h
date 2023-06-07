#pragma once
#include "..\..\stdafx.h"

namespace Whispers {
namespace Manager {
class GraphicManager {
   private:
    sf::RenderWindow* window;
    static GraphicManager* pGraphic;
    View camera;
    GraphicManager();

   public:
    ~GraphicManager();
    static GraphicManager* getGraphicManager();
    sf::RenderWindow* getWindow();
    sf::Font LoadFont(const char* FontPath);
    Texture loadTexture(const char* path);
    void clearWindow();
    void drawElement(sf::RectangleShape shape);
    void drawElement(sf::Text text);
    void showElement();
    void closeWindow();
    const bool isWindowOpen();
    void updateCamera(const Vector2f playerPosition);
    const View getCamera();
    void ResetWindow();
};
}  // namespace Manager
}  // namespace Whispers