#include "..\include\Menu\RankingMenu.h"
#include <fstream>
using namespace Whispers::Menu;

RankingMenu::RankingMenu()
    : Menu(ID::ID::Main_Menu, sf::Vector2f(BUTTON_SIZE_X, BUTTON_SIZE_Y), "Ranking", 180),
      Exit(false),
      RankingMenuObserver(new Observer::RankingMenuObserver(this)),
      background(ID::ID::midnight_background)
{
    if (RankingMenuObserver == nullptr)
    {
        std::cout << "Erro observer menu" << std::endl;
    }
    menuname.SetPos(sf::Vector2f(windowsize.x / 2.0f - menuname.GetSize().x / 2.0f, 25.0f));
    menuname.SetColorText(sf::Color::White);
    CreateBackground();
    CreateButtons();
}

RankingMenu::~RankingMenu()
{
    if (RankingMenuObserver)
    {
        delete (RankingMenuObserver);
        RankingMenuObserver = nullptr;
    }
}
void RankingMenu::CreateBackground()
{
    background.addLayer(PATH_TEXTURE_MAIN_MENU);
}
void RankingMenu::CreateButtons()
{
    const float posbuttonX = windowsize.x / 2.0f - buttonsize.x / 2.0f;
    int size = 0;
    std::ifstream rankFile("ranking/ranking.txt");
    std::string line;
    vector<int> numbers;
    int number;
    if (!rankFile)
    {
        std::cout << "erro ao abrir ranking" << std::endl;
        exit(1);
    }
    else
    {
        while (getline(rankFile, line))
        {
            number = stoi(line);
            numbers.push_back(number);
        }
        sort(numbers.begin(), numbers.end(), greater<int>());
    }
    for (int i = 0; i < numbers.size() && i < 3; i++)
    {
        line = "jogador......" + std::to_string(numbers[i]);
        AddButton(line, sf::Vector2f(posbuttonX, windowsize.y / 2.0f + buttonsize.y * (2 * (float)i)), ID::ID::reload_button, sf::Color::White);
        size++;
    }    
    AddButton("Exit", sf::Vector2f(posbuttonX, windowsize.y / 2.0f + buttonsize.y * (2 * (float)size)), ID::ID::exit_button, sf::Color::White);
    it = buttonlist.begin();
    (*it)->SetSelected(true);
}
void RankingMenu::SetExit(const bool exit)
{
    this->Exit = exit;
}
const bool RankingMenu::GetExit() const
{
    return Exit;
}

void RankingMenu::ChangeObserverState()
{
    RankingMenuObserver->changeActiveState();
}

void RankingMenu::Execute()
{
    backgroundpos = sf::Vector2f(backgroundpos.x + 0.05f, backgroundpos.y);
    pGraphic->updateCamera(sf::Vector2f(backgroundpos.x + windowsize.x / 2.0f, backgroundpos.y + windowsize.y / 2.0f));
    background.execute();
    pGraphic->ResetWindow();
    draw();
    //drawRank();
    pGraphic->drawElement(menuname.GetText());
}
