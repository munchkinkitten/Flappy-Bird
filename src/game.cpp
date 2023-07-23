#include <background.hpp>
#include <bird.hpp>
#include <collisions_checker.hpp>
#include <game.hpp>
#include <iostream>
#include <pipe_controller.hpp>
#include <score_counter.hpp>

int frame = 0;



Game::Game() : window(sf::VideoMode(900, 504), "Flappy Bird", sf::Style::Close)
{
    //pipe = new Pipe();
}

void Game::init()
{
    backgroud = new Background("resources/images/background.png");
    window.setFramerateLimit(60);
    bird               = new Bird();
    pipe_controller    = new PipeController();
    collisions_checker = new CollisionsChecker(bird, pipe_controller->get_pipes_list());
    game_over_texture  = new Texture("resources/images/game_over.png");
    enter_to_start     = new Texture("resources/images/enter.png");
    score_counter      = new ScoreCounter();

    collision_sb.loadFromFile("resources/sounds/collision.wav");
    collision_sound.setBuffer(collision_sb);
    music.openFromFile("resources/sounds/music.wav");
    m_stage = GameStage::Launched;
    stop_update();

}

Game& Game::instance()
{
    static Game game;
    return game;
}

void Game::reset()
{
    m_stage = GameStage::Playing;
    pipe_controller->clear_pipes();
    bird->set_update_status(true);
    pipe_controller->set_update_status(true);
    backgroud->set_update_status(true);
    collisions_checker->set_update_status(true);
    score_counter->set_update_status(true);
    bird->reset();
    score_counter->reset();
}

void Game::update_events()
{
    // Обробка подій вікна
    sf::Event event;

    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();

        if (m_stage == GameStage::GameOver || m_stage == GameStage::Launched)
        {
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Key::Enter)
            {
                reset();
            }
        }
        else
        {
            bird->check_event(event);
        }
    }
}


void Game::run()
{
    //run();
    init();

    auto g_over_size = game_over_texture->sizef() / 2.0f;

    enter_to_start->set_position({float(Game::instance().get_window().getSize().x * 1.25 / 2) - g_over_size.x,
                                  float(Game::instance().get_window().getSize().y * 1.5 / 2) - g_over_size.y});
    enter_to_start->set_scale({0.2, 0.2});
    game_over_texture->set_position({float(Game::instance().get_window().getSize().x / 2) - g_over_size.x,
                                     float(Game::instance().get_window().getSize().y / 2) - g_over_size.y});

    while (window.isOpen())
    {
        frame++;
        update_events();

        if (!(music.getStatus() == sf::SoundSource::Playing))
        {
            music.setVolume(60);
            music.setLoop(true);
            music.play();
        }

        // Етап малювання вікна з урахуванням обробки подій клавіатури
        window.clear(sf::Color::White);

        Object::update_all();
        Object::render_all(window);

        switch(m_stage)
        {
        case GameStage::GameOver:
            game_over_texture->render(window);
            break;
        case GameStage::Launched:
            enter_to_start->render(window);
            break;

        default:
            break;
        }

        window.display();
    }
}

void Game::stop_update()
{
    bird->set_update_status(false);
    pipe_controller->set_update_status(false);
    backgroud->set_update_status(false);
    collisions_checker->set_update_status(false);
    score_counter->set_update_status(false);
}

void Game::game_over()
{
    m_stage = GameStage::GameOver;
    collision_sound.play();
    stop_update();
}

sf::RenderWindow& Game::get_window()
{
    return window;
}

Bird* Game::get_bird()
{
    return bird;
}

PipeController* Game::get_pipe_controller()
{
    return pipe_controller;
}


Game::~Game()
{
    delete backgroud;
    delete bird;
    delete pipe_controller;
    delete collisions_checker;
    delete score_counter;
    delete game_over_texture;
    backgroud = nullptr;
}
