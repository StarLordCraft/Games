#include "Game.hpp"

//COnstructor/destructor
Game::Game()
{
    this->window = new WindowGame();
    
    //Game Logic 
    this->points = 0;
    this->enemySpawnTimer = 0.f;
    this->enemySpawnTimerMax = 10.f;
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
        switch (this->event.type){
        case sf::Event::Closed:
            window->close();
            break;

        case sf::Event::MouseMoved:
            this->window->updateMousePosition();
            break;

        case sf::Event::KeyPressed:
            int key = this->event.key.code;
            auto it = keyboard::keys.find(key);
            if(it != keyboard::keys.end())
                it->second(*window);
            break;


        }
    }
}

void Game::initEnemy()
{
    this->enemy.setSize(sf::Vector2f(100.f, 100.f));
    this->enemy.setScale(sf::Vector2f(1.f, 1.f));


    this->enemy.setOutlineThickness(1.f);
    this->enemy.setOutlineColor(sf::Color::White);
}

void Game::spawnEnemy()
{
    this->initEnemy();

    this->enemy.setPosition(
        static_cast<float>(rand() % static_cast<int>(this->window->getWindow()->getSize().x - this->enemy.getSize().x)),
        0.f
    );

    int r = rand() % 255, g = rand() % 255, b = rand() % 255;
    
    this->enemy.setFillColor(sf::Color(r, g, b, 255));

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

    auto it = this->enemies.begin();
    while (it != this->enemies.end()) {
        auto& enemy = *it;
        
        enemy.move(0.f, 5.f);
        if(enemy.getPosition().y + enemy.getSize().y >= this->window->getWindow()->getSize().y){
            this->enemies.erase(it);
            continue;
        }
        
        this->window->drawEnemies(enemy);

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            if(enemy.getGlobalBounds().contains(this->window->getMousePosition())){
                this->enemies.erase(it);
            }
        }
        ++it;
    }
}

void Game::gameLoop()
{
    sf::RenderWindow* window = this->window->getWindow();

    while(window->isOpen())
    {
        this->events();

        window->clear();

            this->updateEnemies();
        
        window->display();
    }
}

void Game::run()
{
    //rendering
    this->gameLoop();
}