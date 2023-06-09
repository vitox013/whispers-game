#include "..\..\include\Level\Graveyard.h"

using namespace Whispers::Level;

Graveyard::Graveyard()
    : Level(ID::ID::graveyard_level, ID::ID::graveyard_background) {}

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