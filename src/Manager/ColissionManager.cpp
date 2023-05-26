#include "..\..\include\Manager\ColissionManager.h"
using namespace Whispers;
using namespace Manager;

ColissionManager::ColissionManager(List::EntityList* List)
{
    EntList = List;
}
ColissionManager::~ColissionManager()
{
    
}

bool ColissionManager::ColissionCalc(Entity::Entity *ent1, Entity::Entity *ent2)
{
    Vector2f pos1 = ent1->getShape().getPosition();
    Vector2f pos2 = ent2->getShape().getPosition();
    Vector2f size1 = ent1->getShape().getSize();
    Vector2f size2 = ent2->getShape().getSize();
    Vector2f distanceCenter(
        fabs((pos1.x + size1.x) - (pos2.x + size2.x)),
        fabs((pos1.y + size1.y) - (pos2.y + size2.y)));
    Vector2f rectangleSum(
        (size1.x / 2.0f + size2.x / 2.0f),
        (size1.y / 2.0f + size2.y / 2.0f));
    Vector2f result = Vector2f((distanceCenter.x - rectangleSum.x), (distanceCenter.y - rectangleSum.y));
    if (result.x < 0.0f && result.y < 0.0f)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void ColissionManager::ColissionCheck()
{
    
    for (int i = 0; i < (int)EntList->getSize() - 1; i++)
    {
        Entity::Entity *ent1 = EntList->operator[](i);
        for (int j = i + 1; i < (int)EntList->getSize(); i++)
        {
            Entity::Entity* ent2 = EntList->operator[](j);
            //if (ColissionCalc(ent1, ent2))
            //{
                ent2->Colission(ColissionCalc(ent2, ent1));
            //}
            
            //ent1->colission(ColissionCalc(ent1, ent2));
        }     
    }
}