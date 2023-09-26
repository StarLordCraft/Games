#pragma once
#include "keys.hpp"

class Game : engine::Game{
    private:
    //Variables
    sf::RectangleShape enemy;
    std::vector <sf::RectangleShape> enemies;
    sf::Event event;

    //game Logic
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