#include "..\include\Observer\RankingMenuObserver.h"
#include "..\..\include\Manager\StateManager.h"
#include "..\..\include\Menu\RankingMenu.h"

using namespace Whispers::Observer;
using namespace Whispers::Menu;

RankingMenuObserver::RankingMenuObserver(Menu::RankingMenu *rankingMenu)
    : Observer(),
      rankingMenu(rankingMenu)
{
}

RankingMenuObserver::~RankingMenuObserver()
{
}
void RankingMenuObserver::PressedKey(const sf::Keyboard::Key key)
{
    switch (key)
    {
    case sf::Keyboard::Enter:
        switch (rankingMenu->GetIDSelectedButton())
        {
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

void RankingMenuObserver::ReleasedKey(const sf::Keyboard::Key key)
{
    switch (key)
    {
    case (sf::Keyboard::Up):
        rankingMenu->SelectAbove();
        break;
    case (sf::Keyboard::Down):
        rankingMenu->SelectBelow();
        break;
    default:
        break;
    }
}
void RankingMenuObserver::SaveRank() {}