#include "..\..\include\Level\Graveyard.h"

using namespace Whispers::Level;

Graveyard::Graveyard(const bool multiplayer)
    : Level(ID::ID::graveyard_level, multiplayer, ID::ID::graveyard_background) {}

Graveyard::~Graveyard() {}

void Graveyard::createBackground() {
    background.addLayer("assets/background/graveyard/graveyard1.png");
}

void Graveyard::createMap() {
    std::ifstream mapFile;
    std::string line;
    mapFile.open("assets/map/graveyard/graveyard.txt");
    if (!mapFile) {
        std::cout << "Error on opening map file" << std::endl;
        exit(1);
    }
    char j = 0;

    while (std::getline(mapFile, line)) {
        for (int i = 0; i < line.size(); i++) {
            if (line[i] != ' ') {
                createEntities(line[i], Vector2i(i, j));
            }
        }
        j++;
    }
    mapFile.close();

    randomCreateEntities();
}

void Graveyard::randomCreateEntities() {
    // Use the current time to seed the Mersenne Twister engine
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 gen(seed);

    std::uniform_int_distribution<> disX(500, 6000);
    std::uniform_int_distribution<> disY(0, 600);
    std::uniform_int_distribution<> disZ(0, 1);

    std::vector<float> prePlatformPos = {300,  900,  1500, 2100, 2700,
                                         3300, 3900, 4500, 5100};

    const int minInstances = 3;
    const int maxInstances = 7;

    std::uniform_int_distribution<> disInstances(minInstances, maxInstances);

    int numInstances1 = disInstances(gen);

    for (int i = 0; i < numInstances1 + 2; i++) {
        std::uniform_int_distribution<> size(0, prePlatformPos.size() - 1);
        int posX = prePlatformPos[size(gen)];
        Vector2f pos(posX, 460.0f);
        obsList.addEntity(entityBuilder.createEntity(ID::ID::platform, pos));
    }

    // Create a vector of possible y-positions for traps and webs
    int numInstances2 = disInstances(gen);
    for (int i = 0; i < numInstances2; i++) {
        int posX = disX(gen);
        int posY = disY(gen);
        Vector2f pos(posX, posY);
        createSkeletons(pos);
    }

    for (int i = 0; i < numInstances2; i++) {
        int posX = disX(gen);
        int posY = disY(gen);
        Vector2f pos(posX, posY);
        charactersList.addEntity(entityBuilder.createEntity(ID::ID::ghost, pos));
    }

    // Keep track of the positions where traps and webs have been placed
    std::vector<Vector2f> trapWebPositions;
    std::vector<Vector2f> platformPositions;
    for (int i = 0; i < obsList.getSize(); i++) {
        if (obsList.operator[](i)->getId() == ID::ID::platform) {
            platformPositions.push_back(obsList.operator[](i)->getPosition());
        }
    }
    int numInstances3 = disInstances(gen);
    for (int i = 0; i < numInstances3; i++) {
        Vector2f pos;
        if (disZ(gen)) {
            pos.x = disX(gen);
            pos.y = 640.0f;
        } else {
            std::uniform_int_distribution<> size(0,
                                                 platformPositions.size() - 1);
            pos = platformPositions[size(gen)];
            pos.y -= 15;
            pos.x += 60;
        }

        // Check if a trap would overlap with an existing trap or web
        bool overlap = false;
        for (const auto &trapWebPos : trapWebPositions) {
            if (std::abs(pos.x - trapWebPos.x) < 100) {
                overlap = true;
                break;
            }
        }

        // Only add the trap if it doesn't overlap with an existing trap or web
        if (!overlap) {
            obsList.addEntity(entityBuilder.createEntity(ID::ID::web, pos));
            trapWebPositions.push_back(pos);
        }
    }
}