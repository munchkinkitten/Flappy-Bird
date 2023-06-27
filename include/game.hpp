#pragma once
#include <SFML/Graphics.hpp>

class Background;
class Bird;
class PipeController;
class CollisionsChecker;

class Game
{
private:
    Background* backgroud;
    sf::RenderWindow window;
    Bird* bird;
    PipeController* pipe_controller;
    CollisionsChecker* collisions_checker;
    class Texture* game_over_texture;
    bool is_game_over = false;

    Game();

public:
    static Game& instance();

    void reset();

    void update_events();

    void run();

    void game_over();

    sf::RenderWindow& get_window();

    ~Game();
};
