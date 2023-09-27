#pragma once
#include "Engine.hpp"

class MenuScreen : public engine::Window {
private:

public:
    MenuScreen(sf::RenderWindow* window) : engine::Window(window){};
    //void render() override;
   
};

class PlayScreen : public engine::Window {
private:

public:
    PlayScreen(sf::RenderWindow* window) : engine::Window(window){};
    //void render() override;

    //play functions
    void drawEnemies(sf::Shape&);
};