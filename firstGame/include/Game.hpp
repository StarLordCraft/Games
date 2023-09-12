#pragma once
#include "Window.hpp"

class Game{
    private:
    //Variables

    //window
    WindowGame *window;
    //Private functions

    //Constructors / Destructors
    public:
    Game();
    virtual ~Game();

    //functions
    void run();
};