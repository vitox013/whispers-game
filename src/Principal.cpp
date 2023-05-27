#include "..\include\Principal.h"

using namespace Whispers;
using namespace Entity;
using namespace Character;

Principal::Principal()
    : pGraphic(pGraphic->getGraphicManager()),
      pEvent(pEvent->getEventManager()),
      charactersList(),
      obsList(),
      Collider(&charactersList, &obsList),
      background() {
    // std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
    // sf::VideoMode fullscreenMode = modes[0];
    // // sf::RenderWindow window(fullscreenMode, "My window",
    // // sf::Style::Fullscreen);
    // player(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(50.0f, 50.0f))

    instantiateEntities();

    execute();
}

Principal::~Principal() { charactersList.clearList(); }

void Principal::createPlatform(Vector2f position) {
    Obstacle::Platform* p1 =
        new Obstacle::Platform(position, Vector2f(400.0f, 40.0f));
    Entity::Entity* e1 = static_cast<Entity::Entity*>(p1);
    obsList.addEntity(e1);
}

void Principal::createEnemy(Vector2f position, Player* player) {
    Enemy::Enemy* enemy = new Enemy::Enemy(
        position, Vector2f(PLAYER_SIZE_X, PLAYER_SIZE_Y), player);
    Entity::Entity* e1 = static_cast<Entity::Entity*>(enemy);
    charactersList.addEntity(e1);
}

void Principal::instantiateEntities() {
    Player* player =
        new Player(Vector2f(700.0f, 400.0f), Vector2f(50.0f, 60.0f));
    Entity::Entity* e1 = static_cast<Entity::Entity*>(player);
    charactersList.addEntity(e1);
    for (int i = 0; i < 10; i++) {
        createPlatform(Vector2f(i * 300.0f, 680.0f));
    }

    createPlatform(sf::Vector2f(500.0f, 500.0f));
    createPlatform(sf::Vector2f(900.0f, 500.0f));
    createPlatform(sf::Vector2f(1200.0f, 400.0f));

    createPlatform(sf::Vector2f(1100.0f, 350.0f));

    pEvent->setPlayer(player);
}

void Principal::execute() {
    while (pGraphic->isWindowOpen()) {
        pEvent->execute();
        pGraphic->clearWindow();
        background.execute();
        charactersList.execute();
        obsList.execute();
        Collider.CollisionCheck();
        pGraphic->showElement();
    }
}
