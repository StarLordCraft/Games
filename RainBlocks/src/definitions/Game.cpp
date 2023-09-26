#include "Game.hpp"
#include "Window.hpp"

//COnstructor/destructor
Game::Game()
{
    this->window = new WindowGame();
    
    //Game Logic 
    this->points = 0; this -> betterScore = this->getBetterScore();
    this->health = 10;

    this->maxEnemies = 10;
    this->enemySpawnTimer = 0.f;
    this->enemySpawnTimerMax = 30.f;

    //iniciando o jogo no menu
    this->gameState = engine::GameState::MENU;
}

Game::~Game()
{
    this->window->~WindowGame();
    delete this->window;
}

//Functions
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
        bool deleted = false;
        auto& enemy = *it;
        
        enemy.move(0.f, 5.f);
        this->window->drawEnemies(enemy);
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            if(enemy.getGlobalBounds().contains(this->window->getMousePosition())){
                deleted = true;

                this->points += 10;
                if(this->points > this->betterScore)
                    this->setBetterScore();
            }
        }

        if(enemy.getPosition().y > this->window->getWindow()->getSize().y || deleted){
            this->enemies.erase(it);
            this->health -= 1;
            continue;
        }
        ++it;
    }
}

void Game::gameOver()
{

}

unsigned int Game::getBetterScore()
{
    std::ifstream betterScoreFile;
    betterScoreFile.open("./../score.txt");
    
        std::string score;
        betterScoreFile >> score;

    betterScoreFile.close();
    
    return static_cast<unsigned int>(std::atoi(score.c_str()));
}

void Game::setBetterScore()
{
    this->betterScore = this->points;
    std::ofstream betterScoreFile("./../score.txt", std::ios::trunc);
    
        betterScoreFile << this->betterScore;
    
    betterScoreFile.close();
}

void Game::gameLoop()
{
    sf::RenderWindow* window = this->window->getWindow();

    this->events();

    window->clear();

    this->updateEnemies();

    window->display();

}