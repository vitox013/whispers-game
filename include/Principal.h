#pragma once

#include ".\Entity\Character\Enemy\Enemy.h"
#include ".\Entity\Character\Player\Player.h"
#include ".\Manager\GraphicManager\GraphicManager.h"
#include "stdafx.h"

namespace Whispers::Entity {
class Principal {
   private:
    Whispers::Manager::GraphicManager* pGraphic;
    vector<Character::Character*> characters;

   public:
    Principal();
    ~Principal();
    void execute();
};
}  // namespace Whispers::Entity
