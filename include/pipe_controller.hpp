#pragma once
#include <object.hpp>
#include <list>

class Pipe;

class PipeController : public Object
{
private:
    std::list<Pipe*> pipes_list;
    sf::Texture pipe_texture;
    int pipe_speed;
    int pipes_distance;
    int min_seen_pipe;

public:

    PipeController();

    void update() override;

    void push_pipe(Pipe* pipe = nullptr);

    void render(sf::RenderWindow& window) override;

    void clear_pipes();

    std::list<Pipe*>& get_pipes_list();

    ~PipeController();
};
