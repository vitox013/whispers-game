#pragma once
#include "..\List\EntityList.h"
#include ".\Ente.h"

namespace Whispers {
namespace Manager {
class ColissionManager {
   private:
    List::EntityList* CharList;
    List::EntityList* ObjList;

   public:
    ColissionManager(List::EntityList* List, List::EntityList* ObjList);
    ~ColissionManager();
    const Vector2f ColissionCalc(Entity::Entity* ent1, Entity::Entity* ent2);
    void ColissionCheck();
};
}  // namespace Manager
}  // namespace Whispers