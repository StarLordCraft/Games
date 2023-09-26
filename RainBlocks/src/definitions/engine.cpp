#include "Engine.hpp"
#include "Window.hpp"

namespace engine {
    void EngineGame::pause()
    {
        
    }
    /// @brief 
    /// @return void
    /**
     should stop the game and render menu!
    */
    void EngineGame::menu()
    {
        this->window->showMenu();
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
                    it->second(*this->window);
                break;

            }
        }
    }

    void EngineGame::run()
    {
        //rendering
        while (window->getWindow()->isOpen()){
            if(engine::GameState::MENU == this->gameState)
                this->menu();
            else if(engine::GameState::PLAY == this->gameState)
                this->gameLoop();
            else break;
        }
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
}