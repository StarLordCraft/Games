#include "Window.hpp"

WindowGame::WindowGame()
{
    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "First Game",
    sf::Style::Titlebar | sf::Style::Close);
}

WindowGame::~WindowGame()
{
    delete this->window;
}

void WindowGame::renderGameLoop()
{
    while(this->window->isOpen()){
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
        
        this->window->clear();



        this->window->display();
        
    }
}
