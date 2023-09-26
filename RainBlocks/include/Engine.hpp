#pragma once

//Standart includes
#include <ctime>
#include <vector>
#include <iostream>
#include <fstream>
#include <functional>
#include <map>

//SFML includes
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

namespace engine {
    enum GameState {
        MENU,
        PAUSE,
        PLAY
    };

    class Game {
        private:
        engine::GameState gameState;

        public:
        void setGameState(engine::GameState);
        engine::GameState getGameState();
    };

    class Window {
    protected:
    //Definitions
    sf::RenderWindow *window;
    //Mouse Position
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;
    void updateMousePosition();


    public:
    Window();
    
    //Getters
    sf::RenderWindow* getWindow();


    };
}