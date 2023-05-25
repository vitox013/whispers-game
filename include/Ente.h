#pragma once
#include ".\Manager\GraphicManager\GraphicManager.h"
#include ".\stdafx.h"
namespace Whispers {
class Ente {
   protected:
    Manager::GraphicManager* pGraphic;

   public:
    Ente();
    ~Ente();
    virtual void draw() = 0;
};
}  // namespace Whispers