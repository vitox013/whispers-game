#pragma once

#include "..\Entity\Entity.h"
#include ".\List.h"

namespace Whispers::List {
class EntityList {
   private:
    List<Entity::Entity> objEntityList;

   public:
    EntityList();
    ~EntityList();
    void addEntity(Entity::Entity* entity);
    void removeEntity(Entity::Entity* entity);
    void removeEntity(int pos);
    const int getSize() const;
    Entity::Entity* operator[](int pos);
    void clearList();
    void execute();
};
}  // namespace Whispers::List
