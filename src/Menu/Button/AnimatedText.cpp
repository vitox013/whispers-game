#include "../../../include/Menu/Button/AnimatedText.h"


using namespace Whispers::Menu::Button;

AnimatedText::AnimatedText(const sf::Font font, const std::string info)
    : Text(font, info),
    brightening(true),
    transparency(255)
{
}

AnimatedText::~AnimatedText()
{
}
void AnimatedText::update()
{
    bordercolor = sf::Color{0, 0, 0, (sf::Uint8)this->transparency};
    textcolor = sf::Color{textcolor.r, textcolor.g, textcolor.b, (sf::Uint8)this->transparency};
    text.setOutlineColor(bordercolor);
    text.setFillColor(textcolor);
}
void AnimatedText::ChangeBrightening()
{
    brightening = !brightening;
}

const bool AnimatedText::GetBrightening() const
{
    return brightening;
}

const int AnimatedText::GetTransparency() const
{
    return transparency;
}

void AnimatedText::SetTransparency(int transparency)
{
    this->transparency = transparency;
    update();
}

void AnimatedText::reset()
{
    transparency = 255;
    update();
}
