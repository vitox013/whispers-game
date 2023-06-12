#pragma once
#include "..\..\include\List\ObserverList.h"
using namespace Whispers::List;
ObserverList::ObserverList()
    : eleobserverList()
{
}

ObserverList::~ObserverList()
{
    eleobserverList.clearList();
}
void Whispers::List::ObserverList::AddObserver(Observer::Observer *observer)
{
    eleobserverList.addElement(observer);
}
void Whispers::List::ObserverList::RemoveObserver(Observer::Observer *observer)
{
    eleobserverList.removeElement(observer);
}
void Whispers::List::ObserverList::RemoveObserver(int pos)
{
    eleobserverList.removeElement(pos);
}
int Whispers::List::ObserverList::GetSize()
{
    return eleobserverList.getSize();
}
Whispers::Observer::Observer *Whispers::List::ObserverList::operator[](int pos)
{
    return eleobserverList.operator[](pos);
}
void Whispers::List::ObserverList::NotifyKeyPressed(const sf::Keyboard::Key key)
{
    for (int i = 0; i < eleobserverList.getSize(); i++)
    {
        Whispers::Observer::Observer *Observer = eleobserverList.operator[](i);
        if (Observer->getActive() == true)
        {
            Observer->PressedKey(key);
        }
        Observer = nullptr;
    }
}
void Whispers::List::ObserverList::NotifyKeyReleased(const sf::Keyboard::Key key)
{
    for (int i = 0; i < eleobserverList.getSize(); i++)
    {
        Whispers::Observer::Observer *Observer = eleobserverList.operator[](i);
        if (Observer->getActive() == true)
        {
            Observer->ReleasedKey(key);
        }
        Observer = nullptr;
    }
}

void Whispers::List::ObserverList::NotifyEndLevel()
{
    for (int i = 0; i < eleobserverList.getSize(); i++)
    {
        Whispers::Observer::Observer *Observer = eleobserverList.operator[](i);
        if (Observer->getActive() == true)
        {
            Observer->SaveRank();
        }
        Observer = nullptr;
    }
}