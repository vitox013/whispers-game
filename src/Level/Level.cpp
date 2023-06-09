#include "..\..\include\Level\Level.h"
#include "..\..\include\Observer\LevelObserver.h"

#include <chrono>
#include <random>
#include <vector>
#include "Level.h"

using namespace Whispers::Level;
using namespace Whispers::Entity::Obstacle;
using namespace Whispers::Entity::Character;

Level::Level(const ID::ID level_id, const ID::ID background_id)
    : Ente(level_id),
      charactersList(),
      obsList(),
      background(background_id),
      pCollider(
          new Manager::CollisionManager(&charactersList, &obsList, &ProjList)),
      entityBuilder()
{
    if (!pCollider)
    {
        std::cout << "Error on creating CollisionManager" << std::endl;
        exit(1);
    }
}

Level::~Level()
{
    if (pCollider)
    {
        delete pCollider;
        pCollider = nullptr;
    }
    charactersList.clearList();
    obsList.clearList();
    ProjList.clearList();
}

void Level::createEntities(char c, const Vector2i position)
{
    Vector2f pos = Vector2f(position.x * 50.0f, position.y * 50.0f);
    switch (c)
    {
    case 'M':
        obsList.addEntity(entityBuilder.createEntity(ID::ID::wall, pos));
        break;
    case '#':
        obsList.addEntity(
            entityBuilder.createEntity(ID::ID::platform, pos));
        break;
    case 'G':
        obsList.addEntity(entityBuilder.createEntity(ID::ID::ground, pos));
        break;
    case 'p':
        charactersList.addEntity(
            entityBuilder.createEntity(ID::ID::player, pos));
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

void Level::draw()
{
    obsList.execute();
    charactersList.execute();
    ProjList.execute();
}

void Level::execute()
{
    background.execute();
    draw();
    pCollider->CollisionCheck();
}

Player *Level::getPlayer()
{
    for (int i = 0; i < charactersList.getSize(); i++)
    {
        if (charactersList.operator[](i)->getId() == ID::ID::player)
        {
            return static_cast<Player *>(charactersList.operator[](i));
        }
    }
    return nullptr;
}

void Level::ChangeObserverState()
{
    levelObserver->changeActiveState();
}
void Level::randomCreateEntities()
{
    // Use the current time to seed the Mersenne Twister engine
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 gen(seed);

    std::uniform_int_distribution<> disX(500, 6000);
    std::uniform_int_distribution<> disY(0, 600);
    std::uniform_int_distribution<> disZ(0, 1);

    std::vector<Vector2f> platformPositions;
    for (int i = 0; i < obsList.getSize(); i++)
    {
        if (obsList.operator[](i)->getId() == ID::ID::platform)
        {
            platformPositions.push_back(obsList.operator[](i)->getPosition());
        }
    }

    const int minInstances = 3;
    const int maxInstances = 7;

    std::uniform_int_distribution<> disInstances(minInstances, maxInstances);

    int numInstances1 = disInstances(gen);
    int numInstances2 = disInstances(gen);
    int numInstances3 = disInstances(gen);
    int numInstances4 = disInstances(gen);

    // Create a vector of possible y-positions for traps and webs

    for (int i = 0; i < numInstances1; i++)
    {
        int posX = disX(gen);
        int posY = disY(gen);
        Vector2f pos(posX, posY);
        charactersList.addEntity(
            entityBuilder.createEntity(ID::ID::skeleton, pos));
    }

    for (int i = 0; i < numInstances2; i++)
    {
        int posX = disX(gen);
        int posY = disY(gen);
        Vector2f pos(posX, posY);
        charactersList.addEntity(
            entityBuilder.createEntity(ID::ID::bat, pos, &ProjList));
    }

    // Keep track of the positions where traps and webs have been placed
    std::vector<Vector2f> trapWebPositions;

    for (int i = 0; i < numInstances3; i++)
    {
        Vector2f pos;
        if (disZ(gen))
        {
            pos.x = disX(gen);
            pos.y = 640.0f;
        }
        else
        {
            std::uniform_int_distribution<> size(0,
                                                 platformPositions.size() - 1);
            pos = platformPositions[size(gen)];
            pos.y -= 20;
            pos.x += 60;
        }
        // Check if a web would overlap with an existing trap or web
        bool overlap = false;
        for (const auto &trapWebPos : trapWebPositions)
        {
            if (std::abs(pos.x - trapWebPos.x) < 200)
            {
                overlap = true;
                break;
            }
        }

        // Only add the web if it doesn't overlap with an existing trap or web
        if (!overlap)
        {
            obsList.addEntity(entityBuilder.createEntity(ID::ID::web, pos));
            trapWebPositions.push_back(pos);
        }
    }

    for (int i = 0; i < numInstances4; i++)
    {
        Vector2f pos;
        if (disZ(gen))
        {
            pos.x = disX(gen);
            pos.y = 640.0f;
        }
        else
        {
            std::uniform_int_distribution<> size(0,
                                                 platformPositions.size() - 1);
            pos = platformPositions[size(gen)];
            pos.y -= 15;
            pos.x += 60;
        }

        // Check if a trap would overlap with an existing trap or web
        bool overlap = false;
        for (const auto &trapWebPos : trapWebPositions)
        {
            if (std::abs(pos.x - trapWebPos.x) < 100)
            {
                overlap = true;
                break;
            }
        }

        // Only add the trap if it doesn't overlap with an existing trap or web
        if (!overlap)
        {
            obsList.addEntity(entityBuilder.createEntity(ID::ID::trap, pos));
            trapWebPositions.push_back(pos);
        }
    }
}
bool Whispers::Level::Level::getIsRunning()
{
    return false;
}