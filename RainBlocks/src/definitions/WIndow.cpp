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

void WindowGame::pollEvents()
{
     while(this->window->pollEvent(this->event)){
            switch (this->event.type)
            {
            case sf::Event::Closed:
                this->window->close();
                break;

            case sf::Event::KeyPressed:
                int key = this->event.key.code;
                auto it = keyboard::keys.find(key);
                if(it != keyboard::keys.end()){
                    it->second(*this->window);
                }
            }
        }
}

void WindowGame::updateMousePosition()
{
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
}

void WindowGame::updateScreen()
{
    this->window->draw(this->enemy);
    this->updateMousePosition();
}

void WindowGame::initEnemies()
{
    this->enemy.setPosition(0, 0);
    this->enemy.setSize(sf::Vector2f(100.f, 100.f));
    this->enemy.setFillColor(sf::Color::Cyan);
    this->enemy.setOutlineColor(sf::Color::Green);
    this->enemy.setOutlineThickness(1.f);

}

void WindowGame::renderGameLoop()
{
    //init a enemy
    this->initEnemies();

    while(this->window->isOpen()){

        this->pollEvents();

        this->window->clear();

        this->updateScreen();

        this->window->display();
        
    }
}