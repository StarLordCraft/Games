#include "keys.hpp"
#include "Window.hpp"

//implementing the keyboard keys

namespace keyboard {
    std::map<int, std::function<void(WindowGame&)>> keys;

    void Escape(WindowGame& window)
    {
        
    }

    void initializeKeys() 
    {
        keys[sf::Keyboard::Escape] = Escape;
    }
}
