#include "Game.hpp"

//COnstructor/destructor
Game::Game()
{

}

Game::~Game()
{
    
}

//Functions
void Game::run()
{
    //rendering
    this->window->RenderGameLoop();
}
