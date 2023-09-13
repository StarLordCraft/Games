#pragma once
#include <vector>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "keys.hpp"

class WindowGame {
private:
    //Definitions
    sf::RenderWindow *window;
    sf::Event event;

    //Mouse Position
    sf::Vector2i mousePosWindow;

    //Game enemy
    sf::RectangleShape enemy;
    std::vector <sf::RectangleShape> enemies;


public:
    //constructor/destructor
    WindowGame();
    ~WindowGame();

    //functions
    void initEnemies();
    void pollEvents();
    void updateMousePosition();
    void updateScreen();
    void renderGameLoop();

};


