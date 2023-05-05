#include "./Player.h"
#include "stdafx.h"

class Principal {
   private:
    sf::RenderWindow window;
    Player player;

   public:
    Principal();
    ~Principal();
    void execute();
};
