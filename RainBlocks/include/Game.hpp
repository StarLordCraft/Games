#pragma once
#include "Engine.hpp"

class Game : public engine::EngineGame{
    private:
    //Variables
    sf::RectangleShape enemy;
    std::vector <sf::RectangleShape> enemies;

    //game Logic
    unsigned short maxEnemies, health; 
    unsigned int points, betterScore;
    float enemySpawnTimer, enemySpawnTimerMax;
    
    //Private functions
    void initEnemy();
    void spawnEnemy();
    void updateEnemies();
    void gameLoop() override;
    void gameOver();
    
    unsigned int getBetterScore();
    void setBetterScore();

    public:
    //Constructors / Destructors
    Game();
    virtual ~Game();
};