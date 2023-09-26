#pragma once

//Standart includes
#include <ctime>
#include <vector>
#include <iostream>
#include <fstream>

//SFML includes
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

//Personal includes
#include "keys.hpp"

class WindowGame; // Foward Declaration

namespace engine {
    enum GameState {
        MENU,
        PAUSE,
        PLAY
    };


    class EngineGame {
        private:
        /// @brief
        // Controlling state

        //Game
        virtual void initGame();
        virtual void gameLoop();

        protected:
        engine::GameState gameState;
        sf::Event event;
        WindowGame *window;

        void events();

        public:
        void run();
        //Take game states
        void pause();
        void menu();
    };

    class Window {
        
    protected:
    //Definitions
    sf::RenderWindow *window;
    //Mouse Position
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

    public:

    //Getters / setters
    void updateMousePosition();
    sf::Vector2f getMousePosition();

    sf::RenderWindow* getWindow();

    };
}