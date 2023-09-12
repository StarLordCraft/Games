#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include <map>

namespace keyboard{
    extern std::map<int, std::function<void(sf::RenderWindow&)>> keys;

    void Escape(sf::RenderWindow& window);
    void initializeKeys();
}

