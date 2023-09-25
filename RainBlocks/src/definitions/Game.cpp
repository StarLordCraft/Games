#include "Game.hpp"

//COnstructor/destructor
Game::Game()
{
    this->window = new WindowGame();
    
    //Game Logic 
    this->points = 0;
    this->enemySpawnTimer = 0.f;
    this->enemySpawnTimerMax = 1000.f;
    this->maxEnemies = 5;
}

Game::~Game()
{
    this->window->~WindowGame();
    delete this->window;
}

//Functions
void Game::events()
{
    sf::RenderWindow* window = this->window->getWindow(); 
    while(window->pollEvent(this->event)){
            switch (this->event.type)
            {
            case sf::Event::Closed:
                window->close();
                break;

            case sf::Event::KeyPressed:
                int key = this->event.key.code;
                auto it = keyboard::keys.find(key);
                if(it != keyboard::keys.end()){
                    it->second(*window);
                }
            }
        }
        delete window;
}

void Game::spawnEnemy()
{
    this->enemy.setPosition(
        static_cast<float>(rand() % static_cast<int>(this->window->getWindow()->getSize().x - this->enemy.getSize().x)),
        static_cast<float>(rand() % static_cast<int>(this->window->getWindow()->getSize().y - this->enemy.getSize().y))
    );
    int r = rand() % 255, g = rand() % 255, b = rand() % 255;
    
    this->enemy.setFillColor(sf::Color(r, g, b, 1));

    this->enemies.push_back(this->enemy);
}

void Game::updateEnemies()
{
    //update the timer and render enemy if need
    if(this->enemies.size() < this->maxEnemies){
        if(this->enemySpawnTimer >= this->enemySpawnTimerMax){
                this->spawnEnemy();
                this->enemySpawnTimer = 0.f;
            }
        else 
            this->enemySpawnTimer += 1.f;
    }
}

void Game::gameLoop()
{
    sf::RenderWindow* window = this->window->getWindow();
    while(window->isOpen())
    {
        this->events();

        window->clear();

        window->display();
    }
    delete window;
}

void Game::run()
{
    //rendering
    this->gameLoop();
}

