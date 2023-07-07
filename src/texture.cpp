#include <texture.hpp>
#include <iostream>

Texture::Texture()
{}

Texture::Texture(const char* filename)
{
    open(filename);
}

void Texture::open(const char* filename)
{
    image.loadFromFile(filename);
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    set_position({0, 0});
}

sf::Vector2u Texture::size()
{
    return texture.getSize();
}

sf::Vector2f Texture::sizef()
{
    return {(float)texture.getSize().x, (float)texture.getSize().y};
}

void Texture::set_rotation(float degree)
{
    sprite.setRotation(degree);
}

sf::Vector2f Texture::get_position()
{
    return sprite.getPosition() - sprite.getOrigin();
}

void Texture::set_position(sf::Vector2f pos)
{
    sprite.setPosition(pos + sprite.getOrigin());
}

void Texture::set_origin(const sf::Vector2f& origin)
{
    sprite.setOrigin(origin);
}

void Texture::render(sf::RenderWindow& window)
{
    window.draw(sprite);
}



