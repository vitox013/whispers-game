#include "..\..\include\Builder\EntityBuilder.h"

using namespace Whispers::Builder;

using namespace Whispers::Entity::Character;
using namespace Whispers::Entity::Character::Enemy;
using namespace Whispers::Entity::Obstacle;
using namespace Whispers::Entity;

EntityBuilder::EntityBuilder(Player* pPlayer) : pPlayer(pPlayer) {}

EntityBuilder::EntityBuilder() : pPlayer(nullptr) {}

EntityBuilder::~EntityBuilder() {}

void EntityBuilder::verifyPlayer() {
    if (pPlayer == nullptr) {
        throw std::runtime_error("Player is null");
    }
}

Entity* EntityBuilder::createEntity(const ID::ID id, const Vector2f pos) {
    Entity::Entity* entity = nullptr;

    // Verificar o ID da entidade e criar a entidade correspondente
    switch (id) {
        case ID::ID::player: {
            Player* player = new Player(pos, Vector2f(50.0f, 70.0f));
            if (player == nullptr) {
                throw std::runtime_error("Player is null");
            }
            if (pPlayer == nullptr) {
                pPlayer = player;
            }
            entity = static_cast<Entity::Entity*>(player);
        } break;
        case ID::ID::skeleton:
            entity = static_cast<Entity::Entity*>(new Skeleton(pos, pPlayer));

            break;
        case ID::ID::bat:
            entity = static_cast<Entity::Entity*>(new Bat(pos, pPlayer));

            break;
        case ID::ID::boss:
            entity = static_cast<Entity::Entity*>(new Boss(pos, pPlayer));

            break;
        case ID::ID::ground:
            entity = static_cast<Entity::Entity*>(
                new Ground(pos, Vector2f(200.0f, 80.0f)));

            break;
        case ID::ID::platform:
            entity = static_cast<Entity::Entity*>(
                new Platform(pos, Vector2f(400.0f, 40.0f)));

            break;
        case ID::ID::trap:
            entity = static_cast<Entity::Entity*>(
                new Trap(pos, Vector2f(50.0f, 50.0f)));

            break;
        case ID::ID::wall:
            entity = static_cast<Entity::Entity*>(
                new Wall(pos, Vector2f(40.0f, 400.0f)));

            break;
        default:
            break;
    }

    return entity;
}