#include "../../include/Manager/CollisionManager.h"
using namespace Whispers;


Manager::CollisionManager::CollisionManager(List::EntityList *charsList,
                                   List::EntityList *obsList,
                                   List::EntityList *ProjeList)
    : CharList(charsList), ObjList(obsList), ProjList(ProjeList),
    pGraphic(pGraphic->getGraphicManager()) {}
Manager::CollisionManager::~CollisionManager() 
{
    if (CharList)
    {
        delete CharList;
    }
    if (ObjList)
    {
        delete ObjList;
    }
    if (ProjList)
    {
        delete ProjList;
    }
    
}

const Vector2f Manager::CollisionManager::CollisionCalc(Entity::Entity *ent1,
                                               Entity::Entity *ent2) {
    Vector2f pos1 = ent1->getPosition();
    Vector2f pos2 = ent2->getPosition();
    Vector2f size1 = ent1->getSize();
    Vector2f size2 = ent2->getSize();
    if (ent2->getId() == ID::ID::trap || ent2->getId() == ID::ID::web) {
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
bool Manager::CollisionManager::outofbounds(Entity::Entity *ent) {
    sf::Vector2f window = sf::Vector2f(pGraphic->getWindow()->getSize().x,pGraphic->getWindow()->getSize().y);
    if (ent->getPosition().x > window.x || ent->getPosition().x <
    0.0f || ent->getPosition().y > window.y || ent->getPosition().y <
    0.0f)
    {
        return true;
    }else
    {
        return false;
    }
}
void Manager::CollisionManager::CollisionCheck() {
    Entity::Entity *ent1;
    Entity::Entity *ent2;
    Vector2f ds;

    // Colissão entre personagens
    for (int i = 0; i < (int)CharList->getSize(); i++) {  
        ent1 = CharList->operator[](i);
        for (int j = 0; j < (int)CharList->getSize(); j++) {
            ent2 = CharList->operator[](j);
            ds = CollisionCalc(ent1, ent2);
            if (ds.x < 0.0f && ds.y < 0.0f) {
                ent1->collision(ent2);
            }
        }
    }
    // Colissão entre personagens e objetos
    for (int i = 0; i < CharList->getSize(); i++) {
        ent1 = CharList->operator[](i);
        for (int j = 0; j < ObjList->getSize(); j++) {
            ent2 = ObjList->operator[](j);
            ds = CollisionCalc(ent1, ent2);
            if (ds.x < 0.0f && ds.y < 0.0f) {
                if (ent2->getId() == ID::ID::platform) {
                    ent2->collision(ent1, ds);
                } else if (ent2->getId() == ID::ID::trap) {
                    ent2->collision(ent1, ds);
                } else if (ent2->getId() == ID::ID::web) {
                    ent2->collision(ent1, ds);
                } else if (ent2->getId() == ID::ID::ground) {
                    ent2->collision(ent1, ds);
                } else if (ent2->getId() == ID::ID::wall) {
                    ent2->collision(ent1, ds);
                }
            }
        }
    }
    // Colissão entre personagens e projeteis
    for (int i = 0; i < CharList->getSize(); i++) {
        ent1 = CharList->operator[](i);
        for (int j = 0; j < ProjList->getSize(); j++) {
            ent2 = ProjList->operator[](j);
            ds = CollisionCalc(ent1, ent2);
            if (ds.x < 0.0f && ds.y < 0.0f) {
                if (ent1->getId() == ID::ID::player || ent1->getId() == ID::ID::player2) {
                    ent1->collision(ent2, ds);
                    ProjList->removeEntity(j);
                }
            }
        }
    }
    // // Colissão entre objetos e projeteis
    //  for (int i = 0; i < ProjList->getSize(); i++) {
    //      ent1 = ProjList->operator[](i);

    //      for (int j = 0; j < ObjList->getSize(); j++) {
    //          ent2 = ObjList->operator[](j);
    //          ds = CollisionCalc(ent1, ent2);
    //          if (ds.x < 0.0f && ds.y < 0.0f) {
    //              if (ent2->getId() == ID::ID::platform ) {
    //                  ent1->collision(ent2, ds);
    //                  ProjList->removeEntity(i);
    //              }
    //          }
    //      }
    //  }
    // // Verifica se está fora da tela
    // for (int j = 0; j < ProjList->getSize(); j++)
    // {
    //     ent1 = ProjList->operator[](j);
    //     if (outofbounds(ent1))
    //     {
    //         ProjList->removeEntity(j);
    //     }
    // }
}