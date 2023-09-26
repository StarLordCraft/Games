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

    //Game initializations
    void initGame() override;
    void initEnemy();
    void spawnEnemy();
    void updateEnemies();

    //Storing and getting betterScore
    unsigned int getBetterScore();
    void setBetterScore();

    //Game Loop
    void gameLoop() override;
    

    public:
    //Constructors / Destructors
    Game();
    virtual ~Game();
};