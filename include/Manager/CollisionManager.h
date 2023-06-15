#pragma once
#include "../List/EntityList.h"
#include "./Ente.h"
#include "GraphicManager/GraphicManager.h"


namespace Whispers {
namespace Manager {
class CollisionManager {
   private:
    List::EntityList *CharList;
    List::EntityList *ObjList;
    List::EntityList *ProjList;
    GraphicManager *pGraphic;

public:
    CollisionManager(List::EntityList *charsList, List::EntityList *ObjList,
                     List::EntityList *ProjeList);
    ~CollisionManager();
    const Vector2f CollisionCalc(Entity::Entity *ent1, Entity::Entity *ent2);
    void CollisionCheck();
    bool outofbounds(Entity::Entity *ent);
};
}  // namespace Manager
}  // namespace Whispers