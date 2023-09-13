#include "Game.hpp"

//COnstructor/destructor
Game::Game()
{
    this->window = new WindowGame();
}

Game::~Game()
{
    this->window->~WindowGame();
}

void Game::run()
{
    //rendering
    this->window->renderGameLoop();
}
