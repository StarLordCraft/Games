#include "Game.hpp"

int main(int argc, char **argv)
{
    std::srand(static_cast<unsigned>(time(NULL)));
    keyboard::initializeKeys();

    Game Game; Game.run();

    return 0;
}