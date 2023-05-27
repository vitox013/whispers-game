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
    Texture loadTexture(const char* path);
    void clearWindow();
    void drawElement(sf::RectangleShape shape);
    void showElement();
    void closeWindow();
    const bool isWindowOpen();
    void updateCamera(const Vector2f playerPosition);
    const View getCamera();
};
}  // namespace Manager
}  // namespace Whispers