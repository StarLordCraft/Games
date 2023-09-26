#pragma once
#include "Window.hpp"
#include "keys.hpp"
#include <ctime>
#include <vector>
#include <iostream>
#include <fstream>

class Game{
    private:
    //Variables
    sf::RectangleShape enemy;
    std::vector <sf::RectangleShape> enemies;
    sf::Event event;

    //game Logic
    int gameState;
    unsigned short maxEnemies, health; 
    unsigned int points, betterScore;
    float enemySpawnTimer, enemySpawnTimerMax;

    //window
    WindowGame *window;
    //Private functions
    void gameLoop();
    void initEnemy();
    void spawnEnemy();
    void updateEnemies();
    void gameOver();
    unsigned int getBetterScore();
    void setBetterScore();

    public:
    //Constructors / Destructors
    Game();
    virtual ~Game();

    //functions
    void events();
    void run();
};