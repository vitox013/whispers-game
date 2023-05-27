#include "..\include\Principal.h"

using namespace Whispers;
using namespace Entity;
using namespace Character;

Principal::Principal()
    : pGraphic(pGraphic->getGraphicManager()),
      pEvent(pEvent->getEventManager()),
      charactersList(),
      obsList(),
      Collider(&charactersList, &obsList) {
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
    Player* player =
        new Player(Vector2f(100.0f, 400.0f), Vector2f(50.0f, 50.0f));
    Enemy::Enemy* enemy = new Enemy::Enemy(Vector2f(0.0f, 400.0f),
                                           Vector2f(50.0f, 50.0f), player);
    Obstacle::Platform* p1 = new Obstacle::Platform(Vector2f(300.0f, 200.0f),
                                                    Vector2f(400.0f, 40.0f));

    Obstacle::Platform* p2 = new Obstacle::Platform(Vector2f(200.0f, 300.0f),
                                                    Vector2f(400.0f, 40.0f));

    Obstacle::Platform* p3 = new Obstacle::Platform(Vector2f(100.0f, 400.0f),
                                                    Vector2f(400.0f, 40.0f));

    Obstacle::Platform* p4 =
        new Obstacle::Platform(Vector2f(0.0f, 560.0f), Vector2f(800.0f, 40.0f));

    Entity::Entity* e1 = static_cast<Entity::Entity*>(enemy);
    Entity::Entity* e2 = static_cast<Entity::Entity*>(player);
    Entity::Entity* e3 = static_cast<Entity::Entity*>(p1);
    Entity::Entity* e4 = static_cast<Entity::Entity*>(p2);
    Entity::Entity* e5 = static_cast<Entity::Entity*>(p3);
    Entity::Entity* e6 = static_cast<Entity::Entity*>(p4);

    charactersList.addEntity(e1);
    charactersList.addEntity(e2);

    obsList.addEntity(e3);
    obsList.addEntity(e4);
    obsList.addEntity(e5);
    obsList.addEntity(e6);

    pEvent->setPlayer(player);
}

void Principal::execute() {
    while (pGraphic->isWindowOpen()) {
        pEvent->execute();
        pGraphic->clearWindow();
        charactersList.execute();
        obsList.execute();
        Collider.ColissionCheck();
        pGraphic->showElement();
    }
}