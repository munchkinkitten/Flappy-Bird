#pragma once

#include <object.hpp>
#include <texture.hpp>

class Bird : public Object
{
private:
    Texture bird_texture;
    float speed = 0.f;
    float G = 0.3f;
    float max_speed = 30.f;

public:
    Bird();

    void render(sf::RenderWindow& window);

    void update();

    void check_event(const sf::Event& event);

    void jump ();
};
