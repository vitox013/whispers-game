#include "./GraphicManager/GraphicManager.h"
#include "./Player/Player.h"
#include "stdafx.h"

namespace Whispers {
class Principal {
   private:
    Manager::GraphicManager* pGraphic;
    Character::Player player;

   public:
    Principal();
    ~Principal();
    void execute();
};
}  // namespace Whispers
