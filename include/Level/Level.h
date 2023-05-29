#pragma once

#include <fstream>

#include "..\Background\Background.h"
#include "..\Ente.h"
#include "..\Entity\Character\Enemy\Bat.h"
#include "..\Entity\Character\Enemy\Boss.h"
#include "..\Entity\Character\Enemy\Enemy.h"
#include "..\Entity\Character\Enemy\Skeleton.h"
#include "..\Entity\Character\Player\Player.h"
#include "..\Entity\Obstacle\Ground.h"
#include "..\Entity\Obstacle\Platform.h"
#include "..\Entity\Obstacle\Trap.h"
#include "..\Entity\Obstacle\Wall.h"
#include "..\List\EntityList.h"
#include "..\Manager\CollisionManager.h"
#include "..\Manager\EventManager\EventManager.h"
#include "..\Manager\GraphicManager\GraphicManager.h"

namespace Whispers::Level {
class Level : public Ente {
   protected:
    List::EntityList charactersList;
    List::EntityList obsList;
    List::EntityList ProjList;
    Background::Background background;
    Manager::CollisionManager* pCollider;

   public:
    Level(ID::ID level_id, const ID::ID background_id, Manager::GraphicManager* pGraphic);
    ~Level();
    void createPlatform(const Vector2f position);
    void createWall(const Vector2f position);
    void createGround(const Vector2f position);
    // void createEnemy(const Vector2f position);
    void createTrap(const Vector2f position);
    void createPlayer(const Vector2f position);
    void createSkeleton(const Vector2f position);
    void createBat(const Vector2f position);
    void createBoss(const Vector2f position);
    virtual void createBackground() = 0;
    virtual void createMap() = 0;
    void createEntities(char c, const Vector2i position);
    void execute();
    void draw();
};
}  // namespace Whispers::Level