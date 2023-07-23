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

enum class GameStage : unsigned int
{
    Launched = 0,
    Playing  = 1,
    GameOver = 2,
};

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
    Texture* enter_to_start;

    sf::SoundBuffer collision_sb;
    sf::Sound collision_sound;
    sf::Music music;

    GameStage m_stage;

    Game();

public:
    static Game& instance();

    void reset();

    void update_events();
    void init();

    void run();

    void stop_update();
    void game_over();

    sf::RenderWindow& get_window();

    Bird* get_bird();
    PipeController* get_pipe_controller();
    inline GameStage get_stage() const
    {
        return m_stage;
    }

    ~Game();
};
