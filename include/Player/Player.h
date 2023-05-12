#include "../Character/Character.h"
#include "../stdafx.h"

namespace Whispers {
namespace Character {
class Player : public Character {
   private:
   public:
    Player(const sf::Vector2f pos, const sf::Vector2f tam);
    ~Player();
    void move();
};
}  // namespace Character
}  // namespace Whispers