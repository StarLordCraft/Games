#include "Window.hpp"

WindowGame::WindowGame()
{
    this->window = new sf::RenderWindow(sf::VideoMode(1000, 800), "Rain Blocks",
    sf::Style::Titlebar | sf::Style::Close);

    this->window->setFramerateLimit(144);
}

WindowGame::~WindowGame()
{ delete this->window; }

void WindowGame::drawEnemies(sf::Shape &enemy)
{ this->window->draw(enemy); }

void WindowGame::showMenu()
{
    
}
