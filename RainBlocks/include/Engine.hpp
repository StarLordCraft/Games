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

namespace engine {
    enum GameState {
        MENU,
        ABOUT,
        PLAY,
        PAUSE,
    };

    class EngineGame {
        private:
        /// @brief
        //Game screens
        std::map <std::string, engine::Window*> screens;
        //define screen to render
        // Controlling state

        //Game
        virtual void initGame();
        virtual void gameLoop();

        protected:
        GameState gameState;

        sf::Event event;
        Window *window;

        void events();

        //deleter / Setters
        void deleteScreens();
        void defineScreen();
        void setScreens(std::map<std::string, engine::Window*> screens);

        public:
        void run();
        //Take game states
        void pause();
        //void menu();
    };


    class Window {
        protected:
        //Definitions
        sf::RenderWindow *window;
        //Mouse Position
        sf::Vector2i mousePosWindow;
        sf::Vector2f mousePosView;

        public:
        Window();
        Window(sf::RenderWindow* window) : window(window)
        { }; 
        virtual ~Window();
        //Getters / setters
        void updateMousePosition();
        sf::Vector2f getMousePosition();

        sf::RenderWindow* getWindow();

        virtual void render();
    };
}