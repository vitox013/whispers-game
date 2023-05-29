#include "..\..\include\Manager\CollisionManager.h"
using namespace Whispers;
using namespace Manager;

CollisionManager::CollisionManager(List::EntityList *charsList,
                                   List::EntityList *obsList)
    : CharList(charsList), ObjList(obsList) {}
CollisionManager::~CollisionManager() {}

const Vector2f CollisionManager::CollisionCalc(Entity::Entity *ent1,
                                               Entity::Entity *ent2) {
    Vector2f pos1 = ent1->getPosition();
    Vector2f pos2 = ent2->getPosition();
    Vector2f size1 = ent1->getSize();
    Vector2f size2 = ent2->getSize();
    if (ent2->getId() == ID::ID::trap) {
        pos2.y = pos2.y - 10.0f;
        size2.x = size2.x - 20.0f;
    }
    Vector2f distanceCenter(
        fabs((pos1.x + size1.x / 2.0f) - (pos2.x + size2.x / 2.0f)),
        fabs((pos1.y + size1.y / 2.0f) - (pos2.y + size2.y / 2.0f)));
    Vector2f rectangleSum((size1.x / 2.0f + size2.x / 2.0f),
                          (size1.y / 2.0f + size2.y / 2.0f));
    return Vector2f((distanceCenter.x - rectangleSum.x),
                    (distanceCenter.y - rectangleSum.y));
}
void CollisionManager::CollisionCheck() {
    for (int i = 0; i < (int)CharList->getSize() - 1; i++) {
        Entity::Entity *ent1 = CharList->operator[](i);
        for (int j = i + 1; i < (int)CharList->getSize(); i++) {
            Entity::Entity *ent2 = CharList->operator[](j);

            Vector2f ds = CollisionCalc(ent1, ent2);
            if (ds.x < 0.0f && ds.y < 0.0f) {
                ent1->collision(ent2);
            }
        }
    }

    for (int i = 0; i < CharList->getSize(); i++) {
        Entity::Entity *ent1 = CharList->operator[](i);
        for (int j = 0; j < ObjList->getSize(); j++) {
            Entity::Entity *ent2 = ObjList->operator[](j);
            sf::Vector2f ds = CollisionCalc(ent1, ent2);
            if (ds.x < 0.0f && ds.y < 0.0f) {
                if (ent2->getId() == ID::ID::platform) {
                    ent2->collision(ent1, ds);
                } else if (ent2->getId() == ID::ID::trap) {
                    ent2->collision(ent1, ds);
                } else if (ent2->getId() == ID::ID::ground) {
                    ent2->collision(ent1, ds);
                } else if (ent2->getId() == ID::ID::wall) {
                    ent2->collision(ent1, ds);
                }
            }
        }
    }
}