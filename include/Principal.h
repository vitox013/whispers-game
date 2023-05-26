#pragma once

#include ".\Entity\Character\Enemy\Enemy.h"
#include ".\Entity\Character\Player\Player.h"
#include ".\List\EntityList.h"
#include ".\Manager\EventManager\EventManager.h"
#include ".\Manager\GraphicManager\GraphicManager.h"
#include ".\Manager\ColissionManager.h"
#include "stdafx.h"

namespace Whispers {
class Principal {
   private:
    Manager::GraphicManager* pGraphic;
    Manager::EventManager* pEvent;
    List::EntityList charactersList;
    Manager::ColissionManager Collider;

public:
    Principal();
    ~Principal();
    void execute();
    void instantiateEntities();
};
}  // namespace Whispers
