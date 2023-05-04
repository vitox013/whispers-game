#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

#define TEXTURE_IMG "./assets/catapimbas.jpg"

int main() {
    std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
    sf::VideoMode fullscreenMode = modes[0];
    // sf::RenderWindow window(fullscreenMode, "My window",
    // sf::Style::Fullscreen);
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    sf::Texture texture;

    if (!texture.loadFromFile(TEXTURE_IMG)) {
        return 1;
    }

    sf::Sprite sprite;

    sprite.setTexture(texture);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear(sf::Color::Black);
        window.draw(sprite);
        window.display();
    }

    return 0;
}