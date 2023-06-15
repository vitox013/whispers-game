#include "../include/Menu/PauseMenu.h"
#include "../include/Observer/PauseMenuObserver.h"

using namespace Whispers::Menu;

PauseMenu::PauseMenu(Level::Level *level)
    : Menu(ID::ID::Pause_Menu, sf::Vector2f(350.0f, 50.0f), "Pause", 100),
      level(level),
      pauseMenuObserver(new Observer::PauseMenuObserver(this)),
      DarkBackground(windowsize),
      DarkPanel(sf::Vector2f(windowsize.x / 2.0f, windowsize.y))
{
    menuname.SetColorText(sf::Color::White);
    DarkBackground.setFillColor(sf::Color::Transparent);
    DarkPanel.setFillColor(sf::Color{128,128,128});
    CreateButtons();
}

PauseMenu::~PauseMenu()
{
    if (pauseMenuObserver)
    {
        delete (pauseMenuObserver);
        pauseMenuObserver = nullptr;
    }
}

void Whispers::Menu::PauseMenu::CreateButtons()
{
    const float posbuttonX = windowsize.x / 2.0f - buttonsize.x / 2.0f;
    AddButton("Continue", sf::Vector2f(posbuttonX, windowsize.y / 2.0f), ID::ID::continue_button, sf::Color::White);
    AddButton("Exit", sf::Vector2f(posbuttonX, windowsize.y / 2.0f + buttonsize.y * 4.0f), ID::ID::exit_button, sf::Color::White);
    it = buttonlist.begin();
    (*it)->SetSelected();
}

void Whispers::Menu::PauseMenu::UpdateBackground()
{
    UpdateBackgroundPos();
    sf::Vector2f posDarkBackground = sf::Vector2f(backgroundpos.x - windowsize.x / 2.0f, backgroundpos.y - windowsize.y / 2.0f);
    DarkBackground.setPosition(posDarkBackground);
    DarkPanel.setPosition(sf::Vector2f(posDarkBackground.x + windowsize.x / 4.0f, posDarkBackground.y));
    pGraphic->drawElement(DarkBackground);
    pGraphic->drawElement(DarkPanel);
}

void Whispers::Menu::PauseMenu::UpdateMenuName()
{
    menuname.SetPos(sf::Vector2f(backgroundpos.x - menuname.GetSize().x / 2.1f, backgroundpos.y - windowsize.y / 2.0f));
    pGraphic->drawElement(menuname.GetText());
}

void Whispers::Menu::PauseMenu::UpdateButtons()
{
    std::list<Button::Button *>::iterator aux;
    int i = 1;
    for (aux = buttonlist.begin(); aux != buttonlist.end(); aux++, i++)
    {
        Button::Button *button = *aux;
        button->UpdatePosition(sf::Vector2f(backgroundpos.x - windowsize.x / 4.6f, backgroundpos.y / 1.5f + (buttonsize.y + 20.0f) * i));
        button = nullptr;
    }
    draw();
}

void Whispers::Menu::PauseMenu::SetLevel(Level::Level *level)
{
    this->level = level;
}

void Whispers::Menu::PauseMenu::ChangeObserverState()
{
    pauseMenuObserver->changeActiveState();
}

void Whispers::Menu::PauseMenu::Execute()
{
    level->draw();
    UpdateBackground();
    UpdateMenuName();
    UpdateButtons();
}
