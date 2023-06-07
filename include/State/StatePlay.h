#pragma once

#include "..\Builder\StateBuilder.h"
#include "..\Entity\Character\Player\Player.h"
#include "..\Level\Midnight.h"
#include "..\Level\Graveyard.h"
#include "..\Manager\GraphicManager\GraphicManager.h"
#include ".\State.h"

namespace Whispers::State {
class StatePlay : public State {
   private:
    Level::Level* level;

   public:
    StatePlay(const ID::ID id, Level::Level* level);
    ~StatePlay();
    void execute();
    Entity::Character::Player* getPlayer();
};
}  // namespace Whispers::State