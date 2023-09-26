#include "Game.hpp"

//COnstructor/destructor
Game::Game()
{
    this->window = new WindowGame();
}

Game::~Game()
{
    
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
}

void Game::run()
{
    //rendering
    this->window->renderGameLoop();
}

