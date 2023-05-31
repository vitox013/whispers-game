#include "..\..\include\Level\Level.h"

using namespace Whispers::Level;
using namespace Whispers::Entity::Obstacle;
using namespace Whispers::Entity::Character;

Level::Level(const ID::ID level_id, const ID::ID background_id)
    : Ente(level_id),
      charactersList(),
      obsList(),
      background(background_id),
      pCollider(new Manager::CollisionManager(&charactersList, &obsList)),
      entityBuilder() {
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

void Level::createEntities(char c, const Vector2i position) {
    Vector2f pos = Vector2f(position.x * 50.0f, position.y * 50.0f);
    switch (c) {
        case 'W':
            obsList.addEntity(entityBuilder.createEntity(ID::ID::wall, pos));
            break;
        case '#':
            obsList.addEntity(
                entityBuilder.createEntity(ID::ID::platform, pos));
            break;
        case 'G':
            obsList.addEntity(entityBuilder.createEntity(ID::ID::ground, pos));
            break;
        case 'T':
            obsList.addEntity(entityBuilder.createEntity(ID::ID::trap, pos));
            break;
        case 'p':
            charactersList.addEntity(
                entityBuilder.createEntity(ID::ID::player, pos));
            break;
        case 'S':
            charactersList.addEntity(
                entityBuilder.createEntity(ID::ID::skeleton, pos));
            break;
        case 'B':
            charactersList.addEntity(
                entityBuilder.createEntity(ID::ID::bat, pos));
            break;
        case 'b':
            charactersList.addEntity(
                entityBuilder.createEntity(ID::ID::boss, pos));
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

Player* Level::getPlayer() {
    for (int i = 0; i < charactersList.getSize(); i++) {
        if (charactersList.operator[](i)->getId() == ID::ID::player) {
            return static_cast<Player*>(charactersList.operator[](i));
        }
    }
    return nullptr;
}