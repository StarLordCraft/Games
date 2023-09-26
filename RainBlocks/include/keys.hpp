#pragma once
#include "Window.hpp"
#include <SFML/Graphics.hpp>
#include <functional>
#include <map>

//defining the keyboard Keys accepted
namespace keyboard{
    enum GameState{
        MENU,
        PAUSE,
        PLAY
    };

    extern std::map<int, std::function<void(WindowGame&)>> keys;

    void Escape(WindowGame& window);
    void initializeKeys();
}

