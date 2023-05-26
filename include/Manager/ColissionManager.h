#pragma once
#include ".\Ente.h"
#include "..\List\EntityList.h"

namespace Whispers{
    namespace Manager{
        class ColissionManager
        {
        private:
            List::EntityList *EntList;

        public:
            ColissionManager(List::EntityList* List);
            ~ColissionManager();
            bool ColissionCalc(Entity::Entity* ent1, Entity::Entity* ent2);
            void ColissionCheck();
        };
    }
}