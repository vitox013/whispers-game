#pragma once

#include "..\..\Ente.h"
#include "AnimatedText.h"

#define FONT_PATH "fonts/Pixeboy.ttf"
#define CHANGE_COLOR_TIME 0.01F

namespace Whispers::Menu::Button
{
    class Button :public Ente
    {
    protected:
        sf::RectangleShape textbox;
        AnimatedText text;
        sf::Vector2f pos;
        sf::Vector2f size;
        bool selected;
        const sf::Color selectedcolor;
        sf::Clock clock;
        const float colortimechange;
        float time;
        const sf::Vector2f GetSizeText() const;

    public:
        Button(const std::string info, const sf::Vector2f size, const sf::Vector2f pos, const ID::ID id, const sf::Color selectedcolor);
        ~Button();
        void draw();
        void TextUpdate();
        void SetSelected(const bool selected = true);
        const bool GetSelected();
        void UpdatePosition(const sf::Vector2f pos);
        const sf::Vector2f GetPos() const;
    };
    
    
    
}