#include "..\..\..\include\Menu\Button\Button.h"

using namespace Whispers::Menu::Button;

Button::Button(const std::string info, const sf::Vector2f size, const sf::Vector2f pos, const ID::ID id, const sf::Color selectedcolor)
    : Ente(id),
      text(pGraphic->LoadFont(FONT_PATH), info),
      selected(false),
      pos(pos),
      size(size),
      clock(),
      colortimechange(CHANGE_COLOR_TIME),
      time(0.0f),
      selectedcolor(selectedcolor)
{
    textbox.setPosition(pos);
    textbox.setSize(size);
    sf::Vector2f textsize = this->text.GetSize();
    sf::Vector2f textpos(pos.x + size.x / 2.0f - textsize.x / 2.05f,
                         pos.y + size.y / 2.0f - textsize.y * 1.2f);
    this->text.SetPos(textpos);
    textbox.setFillColor(sf::Color::Transparent);
}

Button::~Button()
{
}

const sf::Vector2f Button::GetSizeText() const
{
    return sf::Vector2f(text.GetText().getGlobalBounds().width, text.GetText().getGlobalBounds().height);
}
void Button::draw()
{
    TextUpdate();
    pGraphic->drawElement(textbox);
    pGraphic->drawElement(text.GetText());
}

void Button::TextUpdate()
{
    const float dt = clock.getElapsedTime().asSeconds();
    clock.restart();
    time += dt;
    if (selected)
    {
        if (time > CHANGE_COLOR_TIME)
        {
            int transparency = text.GetTransparency();
            if (text.GetBrightening())
            {
                transparency += 5;
                if (transparency > 255)
                {
                    transparency = 255; // Clareando texto
                    text.ChangeBrightening();
                }
            }
            else
            {
                transparency -= 5;
                if (transparency < 0)
                {
                    transparency = 0; // Escurecendo texto
                    text.ChangeBrightening();
                }
            }
            text.SetTransparency(transparency);
            time = 0.0f;
        }
    }
    else
    {
        time = 0.0f;
    }
}

void Button::SetSelected(const bool selected)
{
    if (selected)
    {
        text.SetColorText(selectedcolor);
    }
    else
    {
        text.SetColorText(sf::Color::White);
    }
    this->selected = selected;
    text.reset();
}

const bool Button::GetSelected()
{
    return selected;
}

void Button::UpdatePosition(const sf::Vector2f pos)
{
    this->pos = pos;
    textbox.setPosition(pos);
    sf::Vector2f textsize = this->text.GetSize();
    sf::Vector2f TextPos(pos.x + size.x / 2.0f - textsize.x / 2.05f,
                         pos.y + size.y / 2.0f - textsize.y * 1.2f);
    this->text.SetPos(TextPos);
}

const sf::Vector2f Button::GetPos() const
{
    return textbox.getPosition();
}
