#pragma once

#include ".\Entity\Character\Enemy\Enemy.h"
#include ".\Entity\Character\Player\Player.h"
#include ".\Entity\Obstacle\Platform.h"
#include ".\List\EntityList.h"
#include ".\Manager\CollisionManager.h"
#include ".\Manager\EventManager\EventManager.h"
#include ".\Manager\GraphicManager\GraphicManager.h"
#include "stdafx.h"

namespace Whispers {
class Principal {
   private:
    Manager::GraphicManager* pGraphic;
    Manager::EventManager* pEvent;
    Manager::CollisionManager Collider;
    List::EntityList charactersList;
    List::EntityList obsList;

   public:
    Principal();
    ~Principal();
    void execute();
    void instantiateEntities();
};
}  // namespace Whispers
