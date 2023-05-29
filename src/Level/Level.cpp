#include "..\..\include\Level\Level.h"

using namespace Whispers::Level;
using namespace Whispers::Entity::Obstacle;
using namespace Whispers::Entity::Character;

Level::Level(const ID::ID level_id, const ID::ID background_id)
    : Ente(level_id),
      background(background_id),
      pCollider(new Manager::CollisionManager(&charactersList, &obsList)) {
    if (!pCollider) {
        std::cout << "Error on creating CollisionManager" << std::endl;
        exit(1);
    }
}

Level::~Level() {
    if (pCollider) {
        delete pCollider;
        pCollider = nullptr;
    }
    charactersList.clearList();
    obsList.clearList();
}

void Level::createPlatform(const Vector2f position) {
    Platform* platform = new Platform(position, Vector2f(400.0f, 40.0f));
    obsList.addEntity(static_cast<Entity::Entity*>(platform));
}

void Level::createWall(const Vector2f position) {
    Wall* wall = new Wall(position, Vector2f(40.0f, 400.0f));
    obsList.addEntity(static_cast<Entity::Entity*>(wall));
}

void Level::createGround(const Vector2f position) {
    Ground* ground = new Ground(position, Vector2f(200.0f, 80.0f));
    obsList.addEntity(static_cast<Entity::Entity*>(ground));
}

void Level::createTrap(const Vector2f position) {
    Trap* trap = new Trap(position, Vector2f(50.0f, 50.0f));
    obsList.addEntity(static_cast<Entity::Entity*>(trap));
}

void Level::createPlayer(const Vector2f position) {
    Manager::EventManager* pEvent = pEvent->getEventManager();
    Player* player = new Player(position, Vector2f(50.0f, 70.0f));

    if (!player) {
        std::cout << "Error on creating Player" << std::endl;
        exit(1);
    }
    pEvent->setPlayer(player);
    charactersList.addEntity(static_cast<Entity::Entity*>(player));
}

void Level::createSkeleton(const Vector2f position) {
    Manager::EventManager* pEvent = pEvent->getEventManager();
    Player* pPlayer = pEvent->getPlayer();
    Enemy::Skeleton* skeleton = new Enemy::Skeleton(position, pPlayer);

    if (!skeleton) {
        std::cout << "Error on creating Skeleton" << std::endl;
        exit(1);
    }
    charactersList.addEntity(static_cast<Entity::Entity*>(skeleton));
}

void Level::createBat(const Vector2f position) {
    Manager::EventManager* pEvent = pEvent->getEventManager();
    Player* pPlayer = pEvent->getPlayer();
    Enemy::Bat* bat = new Enemy::Bat(position, pPlayer);

    if (!bat) {
        std::cout << "Error on creating Bat" << std::endl;
        exit(1);
    }
    charactersList.addEntity(static_cast<Entity::Entity*>(bat));
}

void Level::createBoss(const Vector2f position) {
    Manager::EventManager* pEvent = pEvent->getEventManager();
    Player* pPlayer = pEvent->getPlayer();
    Enemy::Boss* boss = new Enemy::Boss(position, pPlayer);

    if (!boss) {
        std::cout << "Error on creating Boss" << std::endl;
        exit(1);
    }
    charactersList.addEntity(static_cast<Entity::Entity*>(boss));
}

void Level::createEntities(char c, const Vector2i position) {
    switch (c) {
        case 'W':
            createWall(Vector2f(position.x * 50.0f, position.y * 50.0f));
            break;
        case '#':
            createPlatform(Vector2f(position.x * 50.0f, position.y * 50.0f));
            break;
        case 'G':
            createGround(Vector2f(position.x * 50.0f, position.y * 50.0f));
            break;
        // case 'E':
        //     createEnemy(Vector2f(position.x * 50.0f, position.y * 50.0f));
        //     break;
        case 'T':
            createTrap(Vector2f(position.x * 50.0f, position.y * 50.0f));
            break;
        case 'p':
            createPlayer(Vector2f(position.x * 50.0f, position.y * 50.0f));
            break;
        case 'S':
            createSkeleton(Vector2f(position.x * 50.0f, position.y * 50.0f));
            break;
        case 'B':
            createBat(Vector2f(position.x * 50.0f, position.y * 50.0f));
            break;
        case 'b':
            createBoss(Vector2f(position.x * 50.0f, position.y * 50.0f));
            break;

        default:
            break;
    }
}

void Level::draw() {
    obsList.execute();
    charactersList.execute();
}

void Level::execute() {
    background.execute();
    draw();
    pCollider->CollisionCheck();
}