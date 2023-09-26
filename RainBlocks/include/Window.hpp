#pragma once
#include "Engine.hpp"

class WindowGame : public engine::Window {
private:


public:
    //constructor/destructor
    WindowGame();
    ~WindowGame();
    
    //getters
    
    void updateMousePosition();

    //play functions
    void drawEnemies(sf::Shape&);
    sf::Vector2f getMousePosition();
};


