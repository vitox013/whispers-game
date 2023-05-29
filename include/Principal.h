#pragma once

#include ".\Level\Midnight.h"
#include ".\Manager\EventManager\EventManager.h"
#include ".\Manager\GraphicManager\GraphicManager.h"
#include "stdafx.h"

namespace Whispers
{
    class Principal
    {
    private:
        Manager::GraphicManager *pGraphic;
        Manager::EventManager *pEvent;
        Level::Midnight *pLevel;
        void createLevel();

    public:
        Principal();
        ~Principal();
        void execute();
    };
} // namespace Whispers
