#include "Engine.hpp"

using namespace engine;

Window::Window()
{
    this->window = new sf::RenderWindow(sf::VideoMode(1000, 800), "Rain Blocks",
    sf::Style::Titlebar | sf::Style::Close);

    this->window->setFramerateLimit(144);
}

sf::RenderWindow* engine::Window::getWindow()
{ return this->window; }


void Window::updateMousePosition()
{
    this->mousePosWindow = sf::Mouse::getPosition(*this->window); 
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow); 
}