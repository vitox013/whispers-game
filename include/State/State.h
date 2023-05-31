#pragma once
#include "..\Ente.h"

namespace Whispers::State {
class State : public Ente {
   protected:
    bool remove;

   public:
    State(const ID::ID id);
    ~State();
    virtual void execute() = 0;
    virtual void draw();
};
}  // namespace Whispers::State