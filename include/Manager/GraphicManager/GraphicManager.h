#include "../../stdafx.h"

namespace Whispers {
namespace Manager {
class GraphicManager {
   private:
    sf::RenderWindow* window;
    static GraphicManager* pGM;
    GraphicManager();

   public:
    ~GraphicManager();
    static GraphicManager* getGraphicManager();
    sf::RenderWindow* getWindow();
    void clearWindow();
    void drawElement(sf::RectangleShape shape);
    void showElement();
    void closeWindow();
    const bool isWindowOpen();
};
}  // namespace Manager
}  // namespace Whispers