#include <iostream>
#include "Window.hpp"
#include "keys.hpp"

int main()
{
    InitializeKeys();
    WindowGame window;
    window.RenderGameLoop();
    return 0;
}