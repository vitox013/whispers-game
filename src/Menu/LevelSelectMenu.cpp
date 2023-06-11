#include "..\include\Menu\LevelSelectMenu.h"

using namespace Whispers::Menu;

LevelSelectMenu::LevelSelectMenu(bool multi)
    : Menu(ID::ID::Level_Select_Menu, sf::Vector2f(BUTTON_SIZE_X, BUTTON_SIZE_Y), "Whispers", 180),
      exit(false),
      LevelSelectMenuObserver(new Observer::LevelSelectMenuObserver(this)),
      background(ID::ID::midnight_background),
      multi(multi)
{
    if (LevelSelectMenuObserver == nullptr)
    {
        std::cout << "Erro observer menu" << std::endl;
    }
    menuname.SetPos(sf::Vector2f(windowsize.x / 2.0f - menuname.GetSize().x / 2.0f, 25.0f));
    menuname.SetColorText(sf::Color::White);
    CreateBackground();
    CreateButtons();
}

LevelSelectMenu::~LevelSelectMenu()
{
    if (LevelSelectMenuObserver)
    {
        delete (LevelSelectMenuObserver);
        LevelSelectMenuObserver = nullptr;
    }
    
}
bool LevelSelectMenu::GetMulti() { return multi; }
void Whispers::Menu::LevelSelectMenu::CreateBackground()
{
    background.addLayer(PATH_TEXTURE_MAIN_MENU);
}
void Whispers::Menu::LevelSelectMenu::CreateButtons()
{
    const float posbuttonX = windowsize.x / 2.0f - buttonsize.x / 2.0f;
    AddButton("Jogar Midnight", sf::Vector2f(posbuttonX, windowsize.y / 2.0f), ID::ID::play_midnight, sf::Color::White);
    AddButton("Jogar Graveyard", sf::Vector2f(posbuttonX, windowsize.y / 2.0f + buttonsize.y * 2.0f), ID::ID::play_graveyard, sf::Color::White);
    AddButton("Exit", sf::Vector2f(posbuttonX, windowsize.y / 2.0f + buttonsize.y * 4.0f), ID::ID::exit_button, sf::Color::White);
    it = buttonlist.begin();
    (*it)->SetSelected(true);
}
void Whispers::Menu::LevelSelectMenu::SetExit(const bool exit)
{
    this->exit = exit;
}
const bool Whispers::Menu::LevelSelectMenu::GetExit() const
{
    return exit;
}

void Whispers::Menu::LevelSelectMenu::ChangeObserverState()
{
    LevelSelectMenuObserver->changeActiveState();
}

void Whispers::Menu::LevelSelectMenu::Execute()
{
    backgroundpos = sf::Vector2f(backgroundpos.x + 0.05f, backgroundpos.y);
    pGraphic->updateCamera(sf::Vector2f(backgroundpos.x + windowsize.x / 2.0f, backgroundpos.y + windowsize.y / 2.0f));
    background.execute();
    pGraphic->ResetWindow();
    draw();
    pGraphic->drawElement(menuname.GetText());
}