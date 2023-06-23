#include <game.hpp>
#include <bird.hpp>
#include <background.hpp>
#include <iostream>
#include <pipe_controller.hpp>

Game::Game() : window(sf::VideoMode(900, 504), "Flappy Bird", sf::Style::Close)
{
    backgroud = new Background("resources/images/background.png");
    window.setFramerateLimit(60);
    bird = new Bird();
    pipe_controller = new PipeController();
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

        bird->check_event(event);
    }
}


void Game::run()
{
    while (window.isOpen())
    {
        update_events();

        // Етап малювання вікна з урахуванням обробки подій клавіатури
        window.clear(sf::Color::White);

        Object::update_all();
        Object::render_all(window);

        window.display();
    }
}

void Game::game_over()
{}

sf::RenderWindow& Game::get_window()
{
    return window;
}

Game::~Game()
{
    delete backgroud;
    delete bird;
    delete pipe_controller;
    backgroud = nullptr;
}
