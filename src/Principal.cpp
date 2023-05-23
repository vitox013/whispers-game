#include "..\include\Principal.h"

using namespace Whispers;

Principal::Principal() : pGraphic(pGraphic->getGraphicManager()), characters(), Collider(characters) {
    // std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
    // sf::VideoMode fullscreenMode = modes[0];
    // // sf::RenderWindow window(fullscreenMode, "My window",
    // // sf::Style::Fullscreen);
    // player(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(50.0f, 50.0f))
    Character::Player* player =
        new Character::Player(Vector2f(0.0f, 0.0f), Vector2f(50.0f, 50.0f));
    Character::Enemy::Enemy* enemy = new Character::Enemy::Enemy(
        Vector2f(0.0f, 10.0f), Vector2f(50.0f, 50.0f), player);

    Character::Character* p1 = static_cast<Character::Character*>(enemy);
    Character::Character* p2 = static_cast<Character::Character*>(player);

    characters.push_back(p1);
    characters.push_back(p2);
    execute();
}

Principal::~Principal() {}

void Principal::execute() {
    while (pGraphic->isWindowOpen()) {
        sf::Event event;
        while (pGraphic->getWindow()->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                pGraphic->closeWindow();
            }
        }
        pGraphic->clearWindow();
        for (int i = 0; i < (int)characters.size(); i++) {
            characters[i]->move();
            Collider.ColissionCheck();
            pGraphic->drawElement(characters[i]->getShape());
        }
        pGraphic->showElement();
    }
}