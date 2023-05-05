#include "../include/Principal.h"

Principal::Principal()
    : window(sf::VideoMode(800, 600), "My window"),
      player(sf::RectangleShape(sf::Vector2f(50.0f, 50.0f))) {
    // std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
    // sf::VideoMode fullscreenMode = modes[0];
    // // sf::RenderWindow window(fullscreenMode, "My window",
    // // sf::Style::Fullscreen);
    execute();
}

Principal::~Principal() {}

void Principal::execute() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear(sf::Color::Black);
        player.move();
        window.draw(player.getShape());
        window.display();
    }
}