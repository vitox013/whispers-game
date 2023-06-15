#pragma once
#include "../../Entity/Character/Player/Player.h"
#include "../GraphicManager/GraphicManager.h"
#include "../StateManager.h"
#include "../../List/ObserverList.h"
#include "stdafx.h"

namespace Whispers::Manager
{
    class EventManager
    {
    private:
        GraphicManager *pGraphic;
        StateManager *pState;
        static EventManager *pEvent;
        static List::ObserverList* pObsList;
        EventManager();

    public:
        ~EventManager();
        static EventManager *getEventManager();
        void AddObserver(Observer::Observer *pObserver);
        void RemoveObserver(Observer::Observer *pObserver);
        void RemoveObserver(int pos);
        void handleKeyPress();
        void execute();
    };
}