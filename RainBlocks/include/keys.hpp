#pragma once
#include "Window.hpp"

//defining the keyboard Keys accepted
namespace keyboard {
    extern std::map<int, std::function<void(WindowGame&)>> keys;

    void Escape(WindowGame& window);
    void initializeKeys();
}

