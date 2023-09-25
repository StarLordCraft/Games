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

