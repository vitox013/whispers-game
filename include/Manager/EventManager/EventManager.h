#pragma once
#include "..\..\Entity\Character\Player\Player.h"
#include "..\GraphicManager\GraphicManager.h"
#include "stdafx.h"

namespace Whispers::Manager {
class EventManager {
   private:
    GraphicManager* pGraphic;
    Entity::Character::Player* pPlayer;

    static EventManager* pEvent;
    EventManager();

   public:
    ~EventManager();
    static EventManager* getEventManager();
    void setPlayer(Entity::Character::Player* pPlayer);
    void handleKeyRelease(Keyboard::Key key);
    void handleKeyPress(Keyboard::Key key);
    void execute();
};
}  // namespace Whispers::Manager