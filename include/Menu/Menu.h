#pragma once
#include "../Ente.h"
#include "Button/Button.h"
#include "Button/Text.h"
#include <list>
#define FONT_PATH "fonts/Pixeboy.ttf"

namespace Whispers::Menu
{
    class Menu :public Ente
    {
    protected:
        std::list<Button::Button *> buttonlist;
        std::list<Button::Button *>::iterator it;
        const sf::Vector2f buttonsize;
        const sf::Vector2f windowsize;
        sf::Vector2f backgroundpos;
        Button::Text menuname;
        bool selectedmouse = false;
        void UpdateBackgroundPos();

    public:
        Menu(const ID::ID id, const sf::Vector2f buttonsize, const std::string name, const unsigned int fontsize);
        ~Menu();
        void AddButton(const std::string info, const sf::Vector2f pos, const ID::ID id, const sf::Color selectedcolor);
        void draw();
        void SelectAbove();
        void SelectBelow();
        const ID::ID GetIDSelectedButton();
        void MouseEvent(const sf::Vector2f mousepos);
        const bool GetMouseSelection() const;
        virtual void Execute() = 0;
    };

}