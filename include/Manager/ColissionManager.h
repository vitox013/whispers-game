#pragma once
#include ".\Ente.h"
#include "..\include\Character\Character.h"

namespace Whispers{
    namespace Manager{
        class ColissionManager
        {
        private:
            //vector<Character::Character*> character_list;

        public:
            ColissionManager();
            ~ColissionManager();
            bool ColissionCalc(Character::Character* ent1, Character::Character* ent2);
            void ColissionCheck(vector<Character::Character *> &list);
        };
    }
}