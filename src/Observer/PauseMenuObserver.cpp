#include "..\include\Observer\PauseMenuObserver.h"
#include "..\..\include\Manager\StateManager.h"

using namespace Whispers::Observer;

PauseMenuObserver::PauseMenuObserver(Menu::PauseMenu *pausemenu)
    : Observer(),
      pauseMenu(pausemenu)
{
}

PauseMenuObserver::~PauseMenuObserver()
{
}

void Whispers::Observer::PauseMenuObserver::PressedKey(const sf::Keyboard::Key key)
{
    switch (key)
    {
    case sf::Keyboard::Enter:
    {
        switch (pauseMenu->GetIDSelectedButton())
        {
        case ID::ID::continue_button:
            pStateMa->popState();
            break;
        case ID::ID::exit_button:
            pStateMa->popState();
            pStateMa->popState();
        default:
            break;
        }
    }
    break;
    default:
        break;
    }
}

void Whispers::Observer::PauseMenuObserver::ReleasedKey(const sf::Keyboard::Key key)
{
    switch (key)
    {
    case (sf::Keyboard::Up):
        pauseMenu->SelectAbove();
        break;
    case (sf::Keyboard::Down):
        pauseMenu->SelectBelow();
        break;
    default:
        break;
    }
}

void Whispers::Observer::PauseMenuObserver::MoveMouse(const sf::Vector2f Mousepos)
{
    pauseMenu->MouseEvent(Mousepos);
}

void Whispers::Observer::PauseMenuObserver::ReleaseMouseButton(const sf::Mouse::Button mousebtn)
{
    if (pauseMenu->GetMouseSelection())
    {
        switch (mousebtn)
        {
        case sf::Mouse::Left:
            switch (pauseMenu->GetIDSelectedButton())
            {
            case ID::ID::continue_button:
                pStateMa->popState();
                break;
            case ID::ID::exit_button:
                pStateMa->popState();
                pStateMa->popState();
                pStateMa->popState();
            default:
                break;
            }
            break;

        default:
            break;
        }
    }
}
void PauseMenuObserver::SaveRank() {}