#pragma once
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "keys.hpp"

class WindowGame {
public:
    WindowGame() : window(sf::VideoMode(800, 600), "SFML window",
    sf::Style::Titlebar | sf::Style::Close)
    {InitializeKeys();}
    void RenderGameLoop();

private:
    sf::RenderWindow window;
    sf::Event event;
};

void WindowGame::RenderGameLoop()
{
    while(this->window.isOpen()){
        while(this->window.pollEvent(this->event)){
            switch (this->event.type)
            {
            case sf::Event::Closed:
                this->window.close();
                break;

            case sf::Event::KeyPressed:
                int key = this->event.key.code;
                auto it = keys.find(key);
                if(it != keys.end()){
                    it->second(this->window);
                }
            }
        }
    }
}
