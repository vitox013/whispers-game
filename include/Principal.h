#pragma once

#include "./Character/Enemy/Enemy.h"
#include "./Character/Player/Player.h"
#include "./Manager/GraphicManager/GraphicManager.h"
#include "stdafx.h"

namespace Whispers {
class Principal {
   private:
    Whispers::Manager::GraphicManager* pGraphic;
    vector<Character::Character*> characters;

   public:
    Principal();
    ~Principal();
    void execute();
};
}  // namespace Whispers
