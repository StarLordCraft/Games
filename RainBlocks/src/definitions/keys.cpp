#include "keys.hpp"
#include "Engine.hpp"
namespace keyboard {
        std::map<int, std::function<void(engine::EngineGame&)>> keys;

        /// @brief
        /// @param window
        /// @return void
        // should pause the game 
        void Escape(engine::EngineGame& engine)
        { engine.pause();}

        void initializeKeys() 
        {
            keys[sf::Keyboard::Escape] = Escape;
        }
    }