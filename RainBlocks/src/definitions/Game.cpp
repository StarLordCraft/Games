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
void Game::run()
{
    //rendering
    this->window->renderGameLoop();
}
