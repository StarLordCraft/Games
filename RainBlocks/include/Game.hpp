#pragma once
#include "Window.hpp"
#include "keys.hpp"
#include <ctime>
#include <vector>

class Game{
    private:
    //Variables
    sf::RectangleShape enemy;
    std::vector <sf::RectangleShape> enemies;
    sf::Event event;

    //game Logic
    unsigned short maxEnemies; 
    unsigned int points, maxPoints;
    float enemySpawnTimer, enemySpawnTimerMax;

    //window
    WindowGame *window;
    //Private functions
    void gameLoop();
    void initEnemy();
    void spawnEnemy();
    void updateEnemies();

    public:
    //Constructors / Destructors
    Game();
    virtual ~Game();

    //functions
    void events();
    void run();
};