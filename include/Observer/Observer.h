#pragma once

#include ".\stdafx.h"

namespace Whispers
{
    namespace Manager
    {
        class EventManager;
        class StateManager;
    }
    namespace Observer
    {
        class Observer
        {
        protected:
            static Manager::EventManager *pEventMa;
            static Manager::StateManager *pStateMa;

        private:
            bool active;

        public:
            Observer();
            virtual ~Observer();
            void changeActiveState();
            const bool getActive() const;
            void RemoveObserver();
            virtual void PressedKey(const sf::Keyboard::Key key) = 0;
            virtual void ReleasedKey(const sf::Keyboard::Key key) = 0;
            virtual void MoveMouse(const sf::Vector2f Mousepos);
            virtual void ReleaseMouseButton(const sf::Mouse::Button mousebtn);
        };
    }

}