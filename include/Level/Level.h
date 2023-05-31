#pragma once

#include <fstream>

#include "..\Background\Background.h"
#include "..\Builder\EntityBuilder.h"
#include "..\Ente.h"
#include "..\List\EntityList.h"
#include "..\Manager\CollisionManager.h"
// using namespace Whispers::Entity::Character;
namespace Whispers::Level {
class Level : public Ente {
   protected:
    List::EntityList charactersList;
    List::EntityList obsList;
    List::EntityList ProjList;
    Background::Background background;
    Manager::CollisionManager* pCollider;
    Builder::EntityBuilder entityBuilder;

   public:
    Level(ID::ID level_id, const ID::ID background_id, Manager::GraphicManager* pGraphic);
    ~Level();
    virtual void createBackground() = 0;
    virtual void createMap() = 0;
    void createEntities(char c, const Vector2i position);
    void execute();
    void draw();
    Entity::Character::Player* getPlayer();
};
}  // namespace Whispers::Level