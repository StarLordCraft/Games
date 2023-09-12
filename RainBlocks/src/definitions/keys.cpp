#include "keys.hpp"

//implementing the keyboard keys
namespace keyboard {
    std::map<int, std::function<void(sf::RenderWindow&)>> keys;

    void Escape(sf::RenderWindow& window)
    {
        window.close();
    }

    void initializeKeys() 
    {
        keys[sf::Keyboard::Escape] = Escape;
    }
}
