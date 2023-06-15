#include "../../include/Observer/Observer.h"
#include "../include/Manager/StateManager.h"
#include "../include/Manager/EventManager/EventManager.h"
using namespace Whispers::Observer;
Whispers::Manager::EventManager *Observer::pEventMa = Whispers::Manager::EventManager::getEventManager();
Whispers::Manager::StateManager *Observer::pStateMa = Whispers::Manager::StateManager::getStateManager();

Observer::Observer()
    : active(true)
{
    pEventMa->AddObserver(this);
}
Observer::~Observer()
{
    RemoveObserver();
}
void Whispers::Observer::Observer::changeActiveState()
{
    if (active == true)
    {
        active = false;
    }
    else
    {
        active = true;
    }
}

const bool Whispers::Observer::Observer::getActive() const
{
    return active;
}

void Whispers::Observer::Observer::RemoveObserver()
{
    pEventMa->RemoveObserver(this);
}
