#include "..\include\Menu\MainMenu.h"

using namespace Whispers::Menu;

MainMenu::MainMenu()
    : Menu(ID::ID::Main_Menu, sf::Vector2f(BUTTON_SIZE_X, BUTTON_SIZE_Y), "Whispers", 180),
      exit(false),
      mainmenuObserver(new Observer::MainMenuObserver(this)),
      background(ID::ID::midnight_background)
{
    if (mainmenuObserver == nullptr)
    {
        std::cout << "Erro observer menu" << std::endl;
    }
    menuname.SetPos(sf::Vector2f(windowsize.x / 2.0f - menuname.GetSize().x / 2.0f, 25.0f));
    menuname.SetColorText(sf::Color::White);
    CreateBackground();
    CreateButtons();
}

MainMenu::~MainMenu()
{
    if (mainmenuObserver)
    {
        delete (mainmenuObserver);
        mainmenuObserver = nullptr;
    }
    
}
void Whispers::Menu::MainMenu::CreateBackground()
{
    background.addLayer(PATH_TEXTURE_MAIN_MENU);
}
void Whispers::Menu::MainMenu::CreateButtons()
{
    const float posbuttonX = windowsize.x / 2.0f - buttonsize.x / 2.0f;
    AddButton("Um Jogador", sf::Vector2f(posbuttonX, windowsize.y / 2.0f), ID::ID::SinglePlayer_Menu, sf::Color::White);
    AddButton("Dois Jogadores", sf::Vector2f(posbuttonX, windowsize.y / 2.0f + buttonsize.y * 2.0f), ID::ID::Multiplayer_Menu, sf::Color::White);
    AddButton("Ranking", sf::Vector2f(posbuttonX, windowsize.y / 2.0f + buttonsize.y * 4.0f), ID::ID::Ranking_Menu, sf::Color::White);
    AddButton("Exit", sf::Vector2f(posbuttonX, windowsize.y / 2.0f + buttonsize.y * 6.0f), ID::ID::exit_button, sf::Color::White);
    it = buttonlist.begin();
    (*it)->SetSelected(true);
}
void Whispers::Menu::MainMenu::SetExit(const bool exit)
{
    this->exit = exit;
}
const bool Whispers::Menu::MainMenu::GetExit() const
{
    return exit;
}

void Whispers::Menu::MainMenu::ChangeObserverState()
{
    mainmenuObserver->changeActiveState();
}

void Whispers::Menu::MainMenu::Execute()
{
    backgroundpos = sf::Vector2f(backgroundpos.x + 0.05f, backgroundpos.y);
    pGraphic->updateCamera(sf::Vector2f(backgroundpos.x + windowsize.x / 2.0f, backgroundpos.y + windowsize.y / 2.0f));
    background.execute();
    pGraphic->ResetWindow();
    draw();
    pGraphic->drawElement(menuname.GetText());
}
