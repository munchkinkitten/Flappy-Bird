#pragma once

#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <object.hpp>
#include <texture.hpp>

class Coin : public Object
{
private:
    Texture coin_texture;
    sf::Vector2f start_position;

    sf::SoundBuffer coin_sb;
    sf::Sound coin_sound;
public:
    Coin();
    Texture& get_texture();
    void reset();
    void render(sf::RenderWindow& window);
    void update();
    void catched(const sf::Vector2f& position);
    ~Coin();
};
