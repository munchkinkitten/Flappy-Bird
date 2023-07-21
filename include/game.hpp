#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/Music.hpp>

class Background;
class Bird;
class PipeController;
class CollisionsChecker;
class ScoreCounter;

class Game
{
private:
    Background* backgroud;
    sf::RenderWindow window;
    Bird* bird;
    PipeController* pipe_controller;
    CollisionsChecker* collisions_checker;
    ScoreCounter* score_counter;

    class Texture* game_over_texture;
    bool is_game_over = false;

    sf::SoundBuffer collision_sb;
    sf::Sound collision_sound;
    sf::Music music;

    Game();

public:
    static Game& instance();

    void reset();

    void update_events();
    void init();

    void run();

    void game_over();

    sf::RenderWindow& get_window();

    Bird* get_bird();
    PipeController* get_pipe_controller();

    ~Game();
};
