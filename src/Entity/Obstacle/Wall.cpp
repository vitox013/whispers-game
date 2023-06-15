#include "../../../include/Entity/Obstacle/Wall.h"

using namespace Whispers::Entity::Obstacle;

Wall::Wall(Vector2f pos, Vector2f size, int type)
    : Obstacle(pos, size, ID::ID::wall,
               type == 1 ? WALL_TEXTURE_GRAVEYARD : WALL_TEXTURE_MIDNIGHT) {}

Wall::~Wall() {}

void Wall::collision(Entity* other, Vector2f ds) {
    Vector2f otherPos = other->getPosition();
    Vector2f otherSize = other->getSize();

    if (other->getId() == ID::ID::player || other->getId() == ID::ID::player2 || other->getId() == ID::ID::enemy ||
        other->getId() == ID::ID::skeleton || other->getId() == ID::ID::bat ||
        other->getId() == ID::ID::boss) {
        collideObstacle(ds, static_cast<Character::Character*>(other));
    }
}

// void Wall::collideObstacle(Vector2f ds, Character::Character* pChar) {
//     Vector2f speed = pChar->getSpeed();
//     if (ds.x < 0.0f && ds.y < 0.0f) {
//         if (ds.x > ds.y) {
//             if (pChar->getId() == ID::ID::player ||
//                 pChar->getId() == ID::ID::enemy ||
//                 pChar->getId() == ID::ID::skeleton ||
//                 pChar->getId() == ID::ID::bat ||
//                 pChar->getId() == ID::ID::boss) {
//                 if (pChar->getPosition().x > position.x) {
//                     speed.x = 0.0f;
//                 }
//             }
//             pChar->setSpeed(speed);
//         }
//     }
// }