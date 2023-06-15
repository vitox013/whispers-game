#pragma once
#include "./ID.h"
#include "./Manager/GraphicManager/GraphicManager.h"
#include "./stdafx.h"
namespace Whispers {
class Ente {
   protected:
    Manager::GraphicManager* pGraphic;
    const ID::ID id;

   public:
    Ente(const ID::ID id);
    ~Ente();
    const ID::ID getId() const;
    virtual void draw() = 0;
};
}  // namespace Whispers