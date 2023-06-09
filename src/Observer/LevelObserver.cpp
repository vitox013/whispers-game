#include "..\include\Observer\LevelObserver.h"
#include "..\include\Manager\StateManager.h"

using namespace Whispers::Observer;

LevelObserver::LevelObserver(Level::Level *level)
    :Observer(), level(level)
{
}

LevelObserver::~LevelObserver()
{
}
void LevelObserver::PressedKey(const sf::Keyboard::Key key)
{
    //push pause state when it's done
}
void LevelObserver::ReleasedKey(const sf::Keyboard::Key key)
{

}
