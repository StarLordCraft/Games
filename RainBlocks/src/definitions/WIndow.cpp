#include "Window.hpp"

WindowGame::WindowGame()
{ }

WindowGame::~WindowGame()
{ delete this->window; }

sf::Vector2f WindowGame::getMousePosition()
{ return this->mousePosView; }

void WindowGame::drawEnemies(sf::Shape &enemy)
{ this->window->draw(enemy); }