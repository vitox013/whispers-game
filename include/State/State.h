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
    void SetRemove(const bool remove = true);
    const bool getRemove() const;
    virtual void ChangeObserverState() = 0;
};
}  // namespace Whispers::State