#include "..\include\Principal.h"

using namespace Whispers;

Principal::Principal()
    : pGraphic(pGraphic->getGraphicManager()),
      pEvent(pEvent->getEventManager()),
      charactersList() {
    // std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
    // sf::VideoMode fullscreenMode = modes[0];
    // // sf::RenderWindow window(fullscreenMode, "My window",
    // // sf::Style::Fullscreen);
    // player(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(50.0f, 50.0f))

    instantiateEntities();

    execute();
}

Principal::~Principal() { charactersList.clearList(); }

void Principal::instantiateEntities() {
    Entity::Character::Player* player = new Entity::Character::Player(
        Vector2f(100.0f, 400.0f), Vector2f(50.0f, 50.0f));
    Entity::Character::Enemy::Enemy* enemy =
        new Entity::Character::Enemy::Enemy(Vector2f(0.0f, 10.0f),
                                            Vector2f(50.0f, 50.0f), player);

    Entity::Entity* p1 = static_cast<Entity::Character::Character*>(enemy);
    Entity::Entity* p2 = static_cast<Entity::Character::Character*>(player);

    charactersList.addEntity(p1);
    charactersList.addEntity(p2);

    pEvent->setPlayer(player);
}

void Principal::execute() {
    while (pGraphic->isWindowOpen()) {
        pEvent->execute();
        pGraphic->clearWindow();
        charactersList.execute();
        pGraphic->showElement();
    }
}