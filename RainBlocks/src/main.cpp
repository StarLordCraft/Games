#include <iostream>
#include "Game.hpp"

int main()
{
    std::srand(static_cast<unsigned>(time(NULL)));
    keyboard::initializeKeys();

    Game Game; Game.run();

    return 0;
}