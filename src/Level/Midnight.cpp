#include "..\..\include\Level\Midnight.h"

using namespace Whispers::Level;

Midnight::Midnight(Manager::GraphicManager* pGraphic)
    : Level(ID::ID::midnight_level, ID::ID::midnight_background, pGraphic) {}

Midnight::~Midnight() {}

void Midnight::createBackground() {
    background.addLayer("assets/background/midnight/midnight.png");
}

void Midnight::createMap() {
    std::ifstream mapFile;
    std::string line;
    mapFile.open("assets/map/midnight/midnight.txt");
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
}