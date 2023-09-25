#include "Window.hpp"

WindowGame::WindowGame()
{
    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Rain Blocks",
    sf::Style::Titlebar | sf::Style::Close);

    this->window->setFramerateLimit(144);
}

WindowGame::~WindowGame()
{
    delete this->window;
}

void WindowGame::updateMousePosition()
{
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
}

sf::RenderWindow* WindowGame::getWindow()
{
    return this->window;
}

void WindowGame::drawEnemies(sf::RectangleShape &enemy)
{
    this->window->draw(enemy);
}