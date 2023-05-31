#pragma once
#include "..\..\Entity\Character\Player\Player.h"
#include "..\GraphicManager\GraphicManager.h"
#include "..\StateManager.h"
#include "stdafx.h"

namespace Whispers::Manager {
class EventManager {
   private:
    GraphicManager* pGraphic;
    StateManager* pState;
    static EventManager* pEvent;
    EventManager();

   public:
    ~EventManager();
    static EventManager* getEventManager();
    void handleKeyPress();
    void execute();
};
}  // namespace Whispers::Manager