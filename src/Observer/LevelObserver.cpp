#include "..\include\Observer\LevelObserver.h"
#include "..\include\Manager\StateManager.h"

using namespace Whispers::Observer;

LevelObserver::LevelObserver(Level::Level *level)
    : Observer(), level(level)
{
}

LevelObserver::~LevelObserver()
{
}
void LevelObserver::PressedKey(const sf::Keyboard::Key key)
{
    switch (key)
    {
    case sf::Keyboard::Escape:
    {
        pStateMa->pushState(ID::ID::Pause_menu_state);
    }
    break;
    }
}
void LevelObserver::ReleasedKey(const sf::Keyboard::Key key)
{
    
}

void LevelObserver::SaveRank()
{
    int score = level->GetEnemiesKilled();
    std::ofstream rankFile("ranking/ranking.txt", ios::app);
    if (!rankFile)
    {
        std::cout << "Error on opening map file" << std::endl;
        exit(1);
    }
    else if (level->getId() == ID::ID::midnight_level)
    {
        std::cout << "Arquivo salvo" << std::endl;
        rankFile << score << "\n";
    }
    else if (level->getId() == ID::ID::graveyard_level)
    {
        std::cout << "Arquivo salvo" << std::endl;
        rankFile << score << "\n";
    }
    rankFile.close();
}