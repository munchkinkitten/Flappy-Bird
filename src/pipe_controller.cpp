#include <game.hpp>
#include <pipe.hpp>
#include <pipe_controller.hpp>

PipeController::PipeController()
{
    pipe_texture.loadFromFile("resources/images/pipe.png");
    pipe_speed     = 2;
    pipes_distance = 200;
    min_seen_pipe  = 80;
    srand(time(NULL));
}

void PipeController::push_pipe(Pipe* pipe)
{
    sf::Vector2f position;
    // Update x position
    static const unsigned int window_width = Game::instance().get_window().getSize().x;

    if (pipes_list.empty())
    {
        position.x = window_width + pipes_distance;
    }
    else
    {
        position.x = pipes_list.back()->get_position().x + pipes_distance + pipe_texture.getSize().x;
    }

    static const unsigned int window_height = Game::instance().get_window().getSize().y;

    int y_min = min_seen_pipe + half_hole_height;
    int y_max = window_height - min_seen_pipe - half_hole_height;

    // Update y position
    position.y = (rand() % (y_max - y_min + 1)) + y_min;

    if (pipe == nullptr)
    {
        pipe = new Pipe(pipe_texture, position);
    }
    else
    {
        pipe->set_position(position);
    }

    pipe->set_complete(false);
    pipes_list.push_back(pipe);
}

void PipeController::update()
{
    for (auto ell : pipes_list)
    {
        ell->set_position({ell->get_position().x - pipe_speed, ell->get_position().y});
    }

    if (pipes_list.empty())
    {
        push_pipe();
    }

    if (pipes_list.front()->get_position().x < -static_cast<int>(pipe_texture.getSize().x))
    {
        Pipe* pipe = pipes_list.front();
        pipes_list.pop_front();
        push_pipe(pipe);
    }

    static const unsigned int window_width = Game::instance().get_window().getSize().x;

    if (window_width - pipes_list.back()->get_position().x - pipe_texture.getSize().x >= pipes_distance)
    {
        push_pipe();
    }
}

/*
 *
*/
// 1) Створення пайпу
// 2)

void PipeController::render(sf::RenderWindow& window)
{
    for (auto ell : pipes_list)
    {
        ell->render(window);
    }
}

void PipeController::clear_pipes()
{
    for (auto ell : pipes_list)
    {
        delete ell;
    }

    pipes_list.clear();
}

std::list<Pipe*>& PipeController::get_pipes_list()
{
    return pipes_list;
}


PipeController::~PipeController()
{
    clear_pipes();
}
