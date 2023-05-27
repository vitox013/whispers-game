#pragma once

#include ".\Background\Background.h"
#include ".\Entity\Character\Enemy\Enemy.h"
#include ".\Entity\Character\Player\Player.h"
#include ".\Entity\Obstacle\Platform.h"
#include ".\List\EntityList.h"
#include ".\Manager\ColissionManager.h"
#include ".\Manager\EventManager\EventManager.h"
#include ".\Manager\GraphicManager\GraphicManager.h"
#include "stdafx.h"

namespace Whispers {
class Principal {
   private:
    Manager::GraphicManager* pGraphic;
    Manager::EventManager* pEvent;
    Manager::ColissionManager Collider;
    List::EntityList charactersList;
    List::EntityList obsList;
    Background::Background background;

   public:
    Principal();
    ~Principal();
    void execute();
    void instantiateEntities();
    void createPlatform(Vector2f position);
    void createEnemy(Vector2f position, Entity::Character::Player* player);
};
}  // namespace Whispers
