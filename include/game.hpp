#pragma once
#include <SFML/Graphics.hpp>

class Background;
class Bird;

class Game
{
private:
    Background* backgroud;
    sf::RenderWindow window;
    Bird* bird;

    Game();

public:
    static Game& instance();

    void reset();

    void update_events();

    void run();

    void game_over ();

    sf::RenderWindow& get_window();

    ~Game();
};
