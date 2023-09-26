#pragma once
#include <map>
#include <functional>

class WindowGame; // Forward declaration

namespace keyboard {
    extern std::map<int, std::function<void(WindowGame&)>> keys;

    void Escape(WindowGame& window);
    void initializeKeys();
}
