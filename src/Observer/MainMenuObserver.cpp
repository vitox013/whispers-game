#include "..\include\Observer\MainMenuObserver.h"
#include "..\..\include\Manager\StateManager.h"
#include "..\..\include\Menu\MainMenu.h"

using namespace Whispers::Observer;
using namespace Whispers::Menu;

MainMenuObserver::MainMenuObserver(Menu::MainMenu *mainmenu)
    : Observer(),
      mainmenu(mainmenu)
{
}

MainMenuObserver::~MainMenuObserver()
{
}
void MainMenuObserver::PressedKey(const sf::Keyboard::Key key)
{
    switch (key)
    {
    case sf::Keyboard::Enter:
        switch (mainmenu->GetIDSelectedButton())
        {
        case (ID::ID::play_midnight):
            pStateMa->pushState(ID::ID::play_midnight);
            break;
        case (ID::ID::play_graveyard):
            pStateMa->pushState(ID::ID::play_graveyard);
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

void Whispers::Observer::MainMenuObserver::ReleasedKey(const sf::Keyboard::Key key)
{
    switch (key)
    {
    case (sf::Keyboard::Up):
        mainmenu->SelectAbove();
        break;
    case (sf::Keyboard::Down):
        mainmenu->SelectBelow();
        break;
    default:
        break;
    }
}

void Whispers::Observer::MainMenuObserver::MoveMouse(const sf::Vector2f Mousepos)
{
    mainmenu->MouseEvent(Mousepos);
}

void Whispers::Observer::MainMenuObserver::ReleaseMouseButton(const sf::Mouse::Button mousebtn)
{
    if (mainmenu->GetMouseSelection())
    {
        switch (mousebtn)
        {
        case sf::Mouse::Left:
            switch (mainmenu->GetIDSelectedButton())
            {
            case (ID::ID::play_midnight):
                pStateMa->pushState(ID::ID::play_midnight);
                break;
            case (ID::ID::play_graveyard):
                pStateMa->pushState(ID::ID::play_graveyard);
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
}