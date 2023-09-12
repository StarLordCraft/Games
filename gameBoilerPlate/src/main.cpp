#include <iostream>
#include "Window.hpp"
#include "keys.hpp"

int main()
{
    keyboard::initializeKeys();

    WindowGame window;
    
    window.RenderGameLoop();
    
    return 0;
}