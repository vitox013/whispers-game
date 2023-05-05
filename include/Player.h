#include "stdafx.h"

class Player {
   private:
    sf::RectangleShape shape;
    sf::Vector2f speed;
    void init();

   public:
    Player(const sf::Vector2f pos, const sf::Vector2f tam);
    Player(const sf::RectangleShape shape);
    Player();
    ~Player();
    const sf::RectangleShape getShape() const;
    void move();
};