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


const sf::Vector2f& Texture::get_position()
{
    return sprite.getPosition();
}

void Texture::set_position(sf::Vector2f pos)
{
    sprite.setPosition(pos);
}

void Texture::render(sf::RenderWindow& window)
{
    window.draw(sprite);
}



