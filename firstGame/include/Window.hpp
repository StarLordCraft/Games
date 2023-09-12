#pragma once
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "keys.hpp"

class WindowGame {
private:
    sf::RenderWindow *window;
    sf::Event event;

public:
    WindowGame();

    ~WindowGame();
    
    void renderGameLoop();

};


//Definitions
