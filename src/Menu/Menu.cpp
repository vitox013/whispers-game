#include "../include/Menu/Menu.h"

using namespace Whispers::Menu;


Menu::Menu(const ID::ID id, const sf::Vector2f buttonsize, const std::string name, const unsigned int fontsize)
    :Ente(id),
    buttonlist(),
    it(),
    buttonsize(buttonsize),
    windowsize(sf::Vector2f(pGraphic->getWindow()->getSize().x,pGraphic->getWindow()->getSize().y)),
    backgroundpos(sf::Vector2f(0.0f,0.0f)),
    menuname(pGraphic->LoadFont(FONT_PATH), name, fontsize)
{
}

Menu::~Menu()
{
    if (!buttonlist.empty())
    {
        for (it = buttonlist.begin();it != buttonlist.end(); it++)
        {
            delete (*it);
            *it = nullptr;
        }
        buttonlist.clear();
    }
    
}
void Whispers::Menu::Menu::UpdateBackgroundPos()
{
    backgroundpos = pGraphic->getCamera().getCenter();
}
void Whispers::Menu::Menu::AddButton(const std::string info, const sf::Vector2f pos, const ID::ID id, const sf::Color selectedcolor)
{
    Button::Button *button = new Button::Button(info, buttonsize, pos, id, selectedcolor);
    if (button == nullptr)
    {
        throw("Nao foi possivel criar botao");
    }
    buttonlist.push_back(button);
}

void Whispers::Menu::Menu::draw()
{
    std::list<Button::Button *>::iterator aux;
    for (aux = buttonlist.begin();aux != buttonlist.end(); aux++)
    {
        Button::Button *button = *aux;
        button->draw();
        button = nullptr;
    }
    
}

void Whispers::Menu::Menu::SelectAbove()
{
    Button::Button *button = *it;
    button->SetSelected(false);
    if (it == buttonlist.begin())
    {
        it = buttonlist.end();
    }
    it--;
    button = *it;
    button->SetSelected(true);
}

void Whispers::Menu::Menu::SelectBelow()
{
    Button::Button *button = *it;
    button->SetSelected(false);
    it++;
    if (it == buttonlist.end())
    {
        it = buttonlist.begin();
    }
    button = *it;
    button->SetSelected(true);
}

const ID::ID Whispers::Menu::Menu::GetIDSelectedButton()
{
    return (*it)->getId();
}

void Whispers::Menu::Menu::MouseEvent(const sf::Vector2f mousepos)
{
    std::list<Button::Button *>::iterator aux;
    selectedmouse = false;
    for (aux = buttonlist.begin();aux != buttonlist.end(); aux++)
    {
        Button::Button *button = *aux;
        sf::Vector2f buttonpos = button->GetPos();
        sf::Vector2f camerapos = pGraphic->getCamera().getCenter();
        if (mousepos.x+camerapos.x - windowsize.x/2.0f > buttonpos.x && mousepos.x+camerapos.x - windowsize.x/2.0f < buttonpos.x + buttonsize.x &&
            mousepos.y+camerapos.y - windowsize.y/2.0f > buttonpos.y && mousepos.y+camerapos.y - windowsize.y/2.0f < buttonpos.y + buttonsize.y)
        {
            (*it)->SetSelected(false);
            it = aux;
            (*it)->SetSelected(true);
            selectedmouse = true;
            break;
        }
        
    }
    
}

const bool Whispers::Menu::Menu::GetMouseSelection() const
{
    return selectedmouse;
}
