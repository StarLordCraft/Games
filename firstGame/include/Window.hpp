#pragma once
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "keys.hpp"

class WindowGame {
public:
    WindowGame()
    {
        window = new sf::RenderWindow(sf::VideoMode(800, 600), "First Game",
        sf::Style::Titlebar | sf::Style::Close);
    }
    ~WindowGame()
    {
        delete this;
    }
    
    void RenderGameLoop();

private:
    sf::RenderWindow *window;
    sf::Event event;
};

void WindowGame::RenderGameLoop()
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
                    it->second(this->window);
                }
            }
        }
        
        this->window->clear();

        this->window->display();
        
    }
}
