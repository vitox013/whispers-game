#include "../include/Observer/LevelSelectMenuObserver.h"
#include "../../include/Manager/StateManager.h"
#include "../../include/Menu/LevelSelectMenu.h"

using namespace Whispers::Observer;
using namespace Whispers::Menu;

LevelSelectMenuObserver::LevelSelectMenuObserver(Menu::LevelSelectMenu *levelSelectMenu)
    : Observer(),
      levelSelectMenu(levelSelectMenu)
{
}

LevelSelectMenuObserver::~LevelSelectMenuObserver()
{
}
void LevelSelectMenuObserver::PressedKey(const sf::Keyboard::Key key)
{
    switch (key)
    {
    case sf::Keyboard::Enter:
        switch (levelSelectMenu->GetIDSelectedButton())
        {
        case (ID::ID::play_midnight):
            pStateMa->pushState(ID::ID::play_midnight, levelSelectMenu->GetMulti());
            break;
        case (ID::ID::play_graveyard):
            pStateMa->pushState(ID::ID::play_graveyard, levelSelectMenu->GetMulti());
            break;
        case (ID::ID::exit_button):
            pStateMa->popState();
            break;
        default:
            break;
        }
        break;

    default:
        break;
    }
}

void LevelSelectMenuObserver::ReleasedKey(const sf::Keyboard::Key key)
{
    switch (key)
    {
    case (sf::Keyboard::Up):
        levelSelectMenu->SelectAbove();
        break;
    case (sf::Keyboard::Down):
        levelSelectMenu->SelectBelow();
        break;
    default:
        break;
    }
}

void LevelSelectMenuObserver::SaveRank() {}