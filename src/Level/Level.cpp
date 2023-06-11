#include "..\..\include\Level\Level.h"

#include "..\..\include\Observer\LevelObserver.h"

using namespace Whispers::Level;
using namespace Whispers::Entity::Obstacle;
using namespace Whispers::Entity::Character;

Level::Level(const ID::ID level_id, const bool multiplayer,
             const ID::ID background_id)
    : Ente(level_id),
      charactersList(),
      obsList(),
      background(background_id),
      pCollider(
          new Manager::CollisionManager(&charactersList, &obsList, &ProjList)),
      entityBuilder(),
      levelObserver(new Observer::LevelObserver(this)),
      multiplayer(multiplayer) {
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
    if (levelObserver) {
        delete (levelObserver);
        levelObserver = nullptr;
    }
}

void Level::createEntities(char c, const Vector2i position) {
    Vector2f pos = Vector2f(position.x * 50.0f, position.y * 50.0f);
    switch (c) {
        case 'M':
            obsList.addEntity(entityBuilder.createEntity(ID::ID::wall, pos));
            break;
        // case '#':
        //     obsList.addEntity(
        //         entityBuilder.createEntity(ID::ID::platform, pos));
        //     break;
        case 'G':
            obsList.addEntity(entityBuilder.createEntity(ID::ID::ground, pos));
            break;
        case 'p':
            charactersList.addEntity(
                entityBuilder.createEntity(ID::ID::player, pos));
            if (multiplayer){
                cout << "multiplayer criado" << endl;
                charactersList.addEntity(
                    entityBuilder.createEntity(ID::ID::player2, pos));
            }
                
            break;
        case 'b':
            charactersList.addEntity(
                entityBuilder.createEntity(ID::ID::boss, pos));
            break;
        case 'm':
            obsList.addEntity(entityBuilder.createEntity(ID::ID::wall_gv, pos));
            break;
        case 'V':
            obsList.addEntity(
                entityBuilder.createEntity(ID::ID::ground_gv, pos));
            break;
        default:
            break;
    }
}

void Level::draw() {
    background.execute();
    obsList.DrawEntities();
    charactersList.DrawEntities();
    ProjList.DrawEntities();
}
void Level::createSkeletons(Vector2f pos) {
    charactersList.addEntity(entityBuilder.createEntity(ID::ID::skeleton, pos));
}

void Level::execute() {
    background.execute();
    obsList.execute();
    charactersList.execute();
    ProjList.execute();
    pCollider->CollisionCheck();
    removeCharacters();
}

Player *Level::getPlayer() {
    for (int i = 0; i < charactersList.getSize(); i++) {
        if (charactersList.operator[](i)->getId() == ID::ID::player) {
            return static_cast<Player *>(charactersList.operator[](i));
        }
    }
    return nullptr;
}

Player *Level::getPlayer2() {
    for (int i = 0; i < charactersList.getSize(); i++) {
        if (charactersList.operator[](i)->getId() == ID::ID::player2) {
            return static_cast<Player *>(charactersList.operator[](i));
        }
    }
    return nullptr;
}

void Level::ChangeObserverState() { levelObserver->changeActiveState(); }

bool Whispers::Level::Level::getIsRunning() { return false; }

void Level::Level::removeCharacters() {
    Character *character = nullptr;
    for (int i = 0; i < charactersList.getSize(); i++) {
        character = static_cast<Character *>(charactersList.operator[](i));
        if (character->getLife() <= 0 && character->getId() != ID::ID::player && character->getId() != ID::ID::player2) {
            charactersList.removeEntity(character);
        }
    }
}