#include <background.hpp>
#include <cmath>

Background::Background(const char* path) : image_1(path), image_2(path)
{
    image_2.set_position({float(image_2.size().x), 0});
}

void Background::update()
{
    if (image_2.get_position().x < 0)
    {
        image_1.set_position({0, 0});
        image_2.set_position({float(image_2.size().x), 0});
    }
    else
    {
        image_1.set_position({image_1.get_position().x - speed, image_1.get_position().y});
        image_2.set_position({image_2.get_position().x - speed, image_2.get_position().y});
    }
}

void Background::render(sf::RenderWindow& window)
{
    image_1.render(window);
    image_2.render(window);
}
