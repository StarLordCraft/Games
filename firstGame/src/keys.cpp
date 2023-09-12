#include "keys.hpp"

std::map<int, std::function<void(sf::RenderWindow&)>> keys;

void Escape(sf::RenderWindow& window)
{
    window.close();
}

void InitializeKeys() 
{
    keys[sf::Keyboard::Escape] = Escape;
}
