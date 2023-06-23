#include <pipe.hpp>

std::size_t hole_height = 140;
std::size_t half_hole_height = hole_height / 2;


Pipe::Pipe(const sf::Texture& texture, sf::Vector2f position) : top(texture), bottom(texture)
{
    top.setRotation(180);

    auto rect = top.getTextureRect();
    rect.left += rect.width;
    rect.width = -rect.width;
    top.setTextureRect(rect);

    set_position(position);
}

void Pipe::render(sf::RenderWindow& window)
{
    window.draw(top);
    window.draw(bottom);
}

const sf::Vector2f& Pipe::get_position()
{
    return position;
}

void Pipe::set_position(sf::Vector2f pos)
{
    // Update bottom sprite position
    bottom.setPosition({pos.x, pos.y + half_hole_height});

    // Update top sprite position
    top.setPosition({pos.x - top.getTextureRect().width, pos.y - half_hole_height});


    position = pos;
}
