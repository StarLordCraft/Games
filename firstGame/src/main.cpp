#include <iostream>
#include "Game.hpp"

int main()
{
    keyboard::initializeKeys();

    Game Game; Game.run();

    return 0;
}