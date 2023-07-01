#pragma once

#include <object.hpp>
#include <texture.hpp>
#include <list>

class Pipe;

class Bird : public Object
{
private:
    size_t texture_index = 0;
    std::vector<Texture*> textures;

    float angle =0.f;
    float speed = 0.f;
    float G = 0.3f;
    float max_speed = 30.f;


public:
    Bird();

    Texture& get_texture();

    void render(sf::RenderWindow& window);
    void set_next_texture();
    void update();
    void reset();
    void set_rotation_angle();
    void check_event(const sf::Event& event);

    void jump ();
    ~Bird();
};
