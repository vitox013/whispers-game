#pragma once

#include <SFML\Graphics.hpp>

namespace Whispers::Menu::Button
{
    class Text
    {
    private:
        const sf::Font font;
        std::string info;

    protected:
        sf::Text text;
        sf::Vector2f size;
        unsigned int fontsize;
        sf::Color textcolor;
        sf::Color bordercolor;
        void initialize();
    public:
        Text(const sf::Font font, const std::string info, const unsigned int fontsize = 50);
        ~Text();
        const sf::Text GetText() const;
        void SetPos(const sf::Vector2f pos);
        sf::Vector2f GetSize();
        void SetColorText(const sf::Color colortext);
    };
}