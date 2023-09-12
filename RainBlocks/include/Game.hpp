#pragma once
#include "Window.hpp"

class Game{
    private:
    //Variables

    //window
    WindowGame *window;
    //Private functions

    public:
    //Constructors / Destructors
    Game();
    virtual ~Game();

    //functions
    void run();
};