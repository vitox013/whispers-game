#pragma once
#include "..\..\stdafx.h"
#include "..\Character.h"
namespace Whispers
{
    namespace Character
    {
        class Player : public Character
        {
        private:
        public:
            Player(const Vector2f pos, const Vector2f size);
            ~Player();
            void move();
            void colission(bool collide);
        };
    } // namespace Character
} // namespace Whispers