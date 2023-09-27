#include "Engine.hpp"

namespace engine {
    ///@brief
    //EngineGame Class definitions
    void EngineGame::pause()
    {
        
    }

    void EngineGame::initGame()
    { }

    void EngineGame::gameLoop()
    {  }

    void EngineGame::events()
    {
        sf::RenderWindow* window = this->window->getWindow(); 
        while(window->pollEvent(this->event)){
            switch (this->event.type){

            case sf::Event::Closed:
                window->close();
                break;

            case sf::Event::MouseMoved:
                this->window->updateMousePosition();
                break;

            default:
            break;

            case sf::Event::KeyPressed:
                int key = this->event.key.code;
                auto it = keyboard::keys.find(key);
                if(it != keyboard::keys.end())
                    it->second(*this);
                break;

            }
        }
    }

    void EngineGame::defineScreen()
    {
        using namespace engine;
        
        switch(this->gameState){
            case GameState::MENU:
                this->window = this->screens["menu"];
                break;
        
            case GameState::ABOUT:
                this->window = this->screens["about"];
                break;
            
            default:
                this->window = this->screens["play"];
                break;
        }
    }


    void EngineGame::deleteScreens()
    { 
        for (const auto& it : this->screens)
        delete it.second;
    }
    
    void EngineGame::setScreens(std::map<std::string, engine::Window*> screens)
    { this->screens = screens; }

    void EngineGame::run()
    {
        //rendering
        while (window->getWindow()->isOpen()){
            if(engine::GameState::MENU == this->gameState);
                //this->menu();
            else if(engine::GameState::PLAY == this->gameState)
                this->gameLoop();
            else break;
        }
    }

    ///@brief
    //Window Class definitions
    Window::Window()
    {
        this->window = new sf::RenderWindow(sf::VideoMode(1000, 800), "Rain Blocks",
        sf::Style::Titlebar | sf::Style::Close);

        this->window->setFramerateLimit(144);
    }

    Window::~Window()
    {
        delete this->window;
    }

    sf::RenderWindow* engine::Window::getWindow()
    { return this->window; }


    void Window::updateMousePosition()
    {
        this->mousePosWindow = sf::Mouse::getPosition(*this->window); 
        this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow); 
    }

    sf::Vector2f Window::getMousePosition()
    { return this->mousePosView; }

    void Window::render()
    {}
}