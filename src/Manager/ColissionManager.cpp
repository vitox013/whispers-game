#include "..\..\include\Manager\ColissionManager.h"
using namespace Whispers;
using namespace Manager;
ColissionManager::ColissionManager(vector<Character::Character *> list)
{
    for (size_t i = 0; i < list.size(); i++)
    {
        character_list[i] = list[i];
    }
    
    
}
ColissionManager::~ColissionManager()
{
    
}

bool ColissionManager::ColissionCalc(Character::Character *ent1, Character::Character *ent2)
{
    sf::Vector2f pos1 = ent1->getPos();
    sf::Vector2f pos2 = ent2->getPos();
    sf::Vector2f size1 = ent1->getSize();
    sf::Vector2f size2 = ent2->getSize();
    sf::Vector2f distanceCenter(
        fabs((pos1.x + size1.x) - (pos2.x + size2.x)),
        fabs((pos1.y + size1.y) - (pos2.y + size2.y)));
    sf::Vector2f rectangleSum(
        (size1.x / 2.0f + size2.x / 2.0f),
        (size1.y / 2.0f + size2.y / 2.0f));
    sf::Vector2f result = sf::Vector2f(distanceCenter.x - rectangleSum.x, distanceCenter.y - rectangleSum.y);
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
    for (int i = 0; i < (int)character_list.size() - 1; i++)
    {
        Character::Character* ent1 = character_list[i];
        for (int j = i + 1; i < (int)character_list.size(); i++)
        {
            Character::Character* ent2 = character_list[j];
            if (ColissionCalc(ent1, ent2) == true)
            {
                ent1->colission();
            }
        }
    }
}