#include <background.hpp>
#include <bird.hpp>
#include <collisions_checker.hpp>
#include <game.hpp>
#include <iostream>
#include <pipe_controller.hpp>


Game::Game() : window(sf::VideoMode(900, 504), "Flappy Bird", sf::Style::Close)
{
    backgroud = new Background("resources/images/background.png");
    window.setFramerateLimit(60);
    bird               = new Bird();
    pipe_controller    = new PipeController();
    collisions_checker = new CollisionsChecker(bird, pipe_controller->get_pipes_list());
    game_over_texture  = new Texture("resources/images/game_over.png");

    //pipe = new Pipe();
}

Game& Game::instance()
{
    static Game game;
    return game;
}

void Game::reset()
{}

void Game::update_events()
{
    // Обробка подій вікна
    sf::Event event;

    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();

        if (is_game_over)
        {
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Key::Space)
            {
                is_game_over = false;
                pipe_controller->clear_pipes();
                bird->set_update_status(true);
                pipe_controller->set_update_status(true);
                backgroud->set_update_status(true);
                collisions_checker->set_update_status(true);
                bird->reset();
            }
        }

        bird->check_event(event);
    }
}


void Game::run()
{

    auto g_over_size = game_over_texture->sizef() / 2.0f;

    game_over_texture->set_position({float(Game::instance().get_window().getSize().x / 2) - g_over_size.x,
                                     float(Game::instance().get_window().getSize().y / 2) - g_over_size.y});

    while (window.isOpen())
    {
        update_events();

        // Етап малювання вікна з урахуванням обробки подій клавіатури
        window.clear(sf::Color::White);

        Object::update_all();
        Object::render_all(window);

        if (is_game_over)
        {
            game_over_texture->render(window);
        }

        window.display();
    }
}

void Game::game_over()
{
    bird->set_update_status(false);
    pipe_controller->set_update_status(false);
    backgroud->set_update_status(false);
    collisions_checker->set_update_status(false);
    is_game_over = true;
}

sf::RenderWindow& Game::get_window()
{
    return window;
}

Game::~Game()
{
    delete backgroud;
    delete bird;
    delete pipe_controller;
    delete collisions_checker;
    delete game_over_texture;
    backgroud = nullptr;
}
