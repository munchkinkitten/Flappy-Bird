#pragma once

#include <object.hpp>
#include <texture.hpp>
#include <list>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

class Pipe;

class Bird : public Object
{
private:
    size_t texture_index = 0;
    std::vector<Texture*> textures;

    sf::SoundBuffer jump_sb;
    sf::Sound jump_sound;

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
