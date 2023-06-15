#pragma once

#include <fstream>
#include <time.h>
#include <chrono>
#include <random>
#include <vector>
#include "../Background/Background.h"
#include "../Builder/EntityBuilder.h"
#include "../Ente.h"
#include "../List/EntityList.h"
#include "../Manager/CollisionManager.h"
// using namespace Whispers::Entity::Character;
namespace Whispers
{
    namespace Observer
    {
        class LevelObserver;
    }
    namespace Level
    {
        class Level : public Ente
        {
        private:
            Observer::LevelObserver *levelObserver;
            int enemiesKilled;

        protected:
            List::EntityList charactersList;
            List::EntityList obsList;
            List::EntityList ProjList;
            Background::Background background;
            Manager::CollisionManager *pCollider;
            Builder::EntityBuilder entityBuilder;
            bool multiplayer;

        public:
            Level(ID::ID level_id, const bool multiplayer, const ID::ID background_id);
            ~Level();
            virtual void createBackground() = 0;
            virtual void createMap() = 0;
            void createEntities(char c, const Vector2i position);
            void execute();
            void draw();
            Entity::Character::Player *getPlayer();
            Entity::Character::Player *getPlayer2();
            void ChangeObserverState();
            virtual void randomCreateEntities() = 0;
            void createSkeletons(Vector2f pos);
            bool getIsRunning();
            void removeCharacters();
            int GetEnemiesKilled();
        };
    }

}
