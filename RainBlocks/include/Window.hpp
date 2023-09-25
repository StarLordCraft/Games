#pragma once
#include <vector>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class WindowGame {
private:
    //Definitions
    sf::RenderWindow *window;

    //Mouse Position
    sf::Vector2i mousePosWindow;


public:
    //constructor/destructor
    WindowGame();
    ~WindowGame();
    
    //getters
    sf::RenderWindow* getWindow();

    //functions
    void drawEnemies(sf::Shape&);
    void updateMousePosition();
};


