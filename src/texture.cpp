#include <texture.hpp>

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
    set_position(sf::Vector2f(texture.getSize().x / 2, texture.getSize().y / 2));
}

sf::Vector2u Texture::size()
{
    return texture.getSize();
}

const sf::Vector2f& Texture::get_position()
{
    return position;
}

void Texture::set_position(sf::Vector2f pos)
{
    position = pos;
    sprite.setPosition(sf::Vector2f(pos.x - texture.getSize().x / 2, pos.y - texture.getSize().y / 2));
}

void Texture::render(sf::RenderWindow& window)
{
    window.draw(sprite);
}



