#pragma once

#include "Text.h"

namespace Whispers::Menu::Button
{
    class AnimatedText :public Text
    {
    private:
        int transparency;
        bool brightening;
        void update();

    public:
        AnimatedText(const sf::Font font, const std::string info);
        ~AnimatedText();
        void ChangeBrightening();
        const bool GetBrightening() const;
        const int GetTransparency() const;
        void SetTransparency(int transparency);
        void reset();
    };
    
    
    
}
