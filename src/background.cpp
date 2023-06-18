#include <background.hpp>
#include <cmath>

Background::Background(const char* path) : image_1(path), image_2(path)
{
    image_2.set_position({float(image_2.size().x / 2 + image_2.size().x), float(image_2.size().y / 2)});
}

void Background::update()
{

    if (std::floor(image_2.get_position().x) == float(image_2.size().x / 2) &&
        std::floor(image_2.get_position().y) == float(image_2.size().y / 2))
    {
        image_1.set_position({float(image_1.size().x / 2), float(image_1.size().y / 2)});
        image_2.set_position({float(image_2.size().x / 2 + image_2.size().x), float(image_2.size().y / 2)});
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
