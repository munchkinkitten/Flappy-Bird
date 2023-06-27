#pragma once

#include <object.hpp>
#include <texture.hpp>

class Pipe;

class Bird : public Object
{
private:
    Texture bird_texture;
    float speed = 0.f;
    float G = 0.3f;
    float max_speed = 30.f;

public:
    Bird();

    Texture& get_texture();

    void render(sf::RenderWindow& window);

    void update();
    void reset();

    void check_event(const sf::Event& event);

    void jump ();
};
