#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class WindowGame {
public:
    WindowGame() : window(sf::VideoMode(800, 600), "SFML window", sf::Style::Titlebar | sf::Style::Close) {
        
    }

private:
    sf::RenderWindow window;
};
