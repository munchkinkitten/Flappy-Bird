#pragma once

#include <SFML/Graphics.hpp>

class Texture
{
private:
    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f position;

public:
    Texture();

    Texture(const char* filename);

    void open(const char* filename);

    sf::Vector2u size();

    const sf::Vector2f& get_position();

    void set_position(sf::Vector2f pos);

    void render(sf::RenderWindow& window);
};
