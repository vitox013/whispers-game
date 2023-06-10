#pragma once

#include "List.h"
#include "..\Observer\Observer.h"

namespace Whispers::List
{
    class ObserverList
    {
    private:
        List<Observer::Observer> eleobserverList;

    public:
        ObserverList();
        ~ObserverList();
        void AddObserver(Observer::Observer *observer);
        void RemoveObserver(Observer::Observer *observer);
        void RemoveObserver(int pos);
        int GetSize();
        Observer::Observer *operator[](int pos);
        void NotifyKeyPressed(const sf::Keyboard::Key key);
        void NotifyKeyReleased(const sf::Keyboard::Key key);
        void NotifyMouseMove(const sf::Event::MouseMoveEvent mouse);
        void NotifyMouseReleased(const sf::Mouse::Button mousebtn);
    };
}