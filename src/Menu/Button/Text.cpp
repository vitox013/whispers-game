#include "..\..\..\include\Menu\Button\Text.h"

using namespace Whispers::Menu::Button;


Text::Text(const sf::Font font, const std::string info, const unsigned int fontsize)
    :font(font),
    text(),
    info(info),
    textcolor(sf::Color::White),
    bordercolor(sf::Color::Black),
    fontsize(fontsize)
{
    initialize();
}

Text::~Text()
{
}
void Text::initialize()
{
    text.setString(info);
    text.setCharacterSize(fontsize);
    
    text.setFont(font);
    text.setOutlineThickness(3);
    text.setOutlineColor(bordercolor);
    text.setFillColor(textcolor);
    size = sf::Vector2f(text.getGlobalBounds().width, text.getGlobalBounds().height);
}
const sf::Text Text::GetText() const
{
    return text;
}
void Text::SetPos(const sf::Vector2f pos)
{
    text.setPosition(pos);
}

sf::Vector2f Text::GetSize()
{
    return size;
}

void Text::SetColorText(const sf::Color colortext)
{
    this->textcolor = colortext;
    text.setFillColor(colortext);
}
