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
    Entity::Character::Player* getPlayer();
    void setPlayer(Entity::Character::Player* pPlayer);
    void handleKeyPress();
    void execute();
};
}  // namespace Whispers::Manager