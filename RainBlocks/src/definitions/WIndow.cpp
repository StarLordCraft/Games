#include "Window.hpp"

WindowGame::WindowGame()
{
    this->window = new sf::RenderWindow(sf::VideoMode(1000, 800), "Rain Blocks",
    sf::Style::Titlebar | sf::Style::Close);

    this->window->setFramerateLimit(144);
}

WindowGame::~WindowGame()
{ delete this->window; }

void WindowGame::updateMousePosition()
{
    this->mousePosWindow = sf::Mouse::getPosition(*this->window); 
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow); 
}

sf::Vector2f WindowGame::getMousePosition()
{ return this->mousePosView; }

sf::RenderWindow* WindowGame::getWindow()
{ return this->window; }

void WindowGame::drawEnemies(sf::Shape &enemy)
{ this->window->draw(enemy); }