#pragma once
#include "..\List\EntityList.h"
#include ".\Ente.h"

namespace Whispers {
namespace Manager {
class CollisionManager {
   private:
    List::EntityList* CharList;
    List::EntityList* ObjList;

   public:
    CollisionManager(List::EntityList* charsList, List::EntityList* ObjList);
    ~CollisionManager();
    const Vector2f CollisionCalc(Entity::Entity* ent1, Entity::Entity* ent2);
    void CollisionCheck();
};
}  // namespace Manager
}  // namespace Whispers