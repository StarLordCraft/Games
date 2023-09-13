#pragma once
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "keys.hpp"

class WindowGame {
private:
    //Definitions
    sf::RenderWindow *window;
    sf::Event event;
    sf::RectangleShape enemy;

public:
    //constructor/destructor
    WindowGame();
    ~WindowGame();

    //functions
    void renderGameLoop();
    void initEnemies();

};


