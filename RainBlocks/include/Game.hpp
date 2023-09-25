#pragma once
#include "Window.hpp"
#include "keys.hpp"
#include <ctime>

class Game{
    private:
    //Variables
    sf::RectangleShape enemy;
    std::vector <sf::RectangleShape> enemies;
    sf::Event event;

    //game Logic
    int points, maxEnemies;
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