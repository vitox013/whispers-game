#pragma once

#include ".\Level\Midnight.h"
#include ".\Manager\EventManager\EventManager.h"
#include ".\Manager\GraphicManager\GraphicManager.h"
#include ".\Manager\StateManager.h"
#include "stdafx.h"

namespace Whispers {
class Principal {
   private:
    Manager::GraphicManager* pGraphic;
    Manager::EventManager* pEvent;
    Manager::StateManager* pState;
    void init();

    public:
        Principal();
        ~Principal();
        void execute();
    };
} // namespace Whispers
