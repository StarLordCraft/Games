#pragma once
#include "Engine.hpp"

class WindowGame : public engine::Window {
private:
        

public:
    //constructor/destructor
    WindowGame();
    ~WindowGame(); 
    //getters

    // menu functions
    void showMenu();

    //play functions
    void drawEnemies(sf::Shape&);
};