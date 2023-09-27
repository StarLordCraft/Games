#pragma once

#include <map>
#include <functional>

namespace engine{
    class EngineGame; // foward declaration
    class Window;
}


namespace keyboard{
    extern std::map<int, std::function<void(engine::EngineGame&)>> keys;

    void Escape(engine::EngineGame& engine);
    void initializeKeys();
}