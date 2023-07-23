#pragma once

#include <SFML/Graphics.hpp>

class Texture
{
private:
    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;

public:
    Texture();

    Texture(const char* filename);

    void open(const char* filename);

    sf::Vector2u size();
    sf::Vector2f sizef();

    void set_rotation(float degree);

    sf::Vector2f get_position();

    void set_position(sf::Vector2f pos);
    void set_origin(const sf::Vector2f& origin);
    void set_scale(const sf::Vector2f& scale);


    void render(sf::RenderWindow& window);
};
