#include "../stdafx.h"

namespace Whispers {
namespace Character {
class Character {
   protected:
    sf::RectangleShape shape;
    sf::Vector2f speed;
    void init();

   public:
    Character(const sf::Vector2f pos, const sf::Vector2f tam);
    ~Character();
    const sf::RectangleShape getShape() const;
    virtual void move() = 0;
};
}  // namespace Character
}  // namespace Whispers