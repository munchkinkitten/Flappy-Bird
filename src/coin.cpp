#include <coin.hpp>
#include <iostream>

Coin::Coin()
{
    std::clog << "Coin created" << std::endl;

    coin_texture.open("resources/images/coin.png");
    start_position = {1250 + static_cast<float>(coin_texture.size().x / 4), 100};
    coin_texture.set_position(start_position);

    coin_sb.loadFromFile("resources/sounds/coin.wav");
    coin_sound.setBuffer(coin_sb);
}

void Coin::reset()
{
    coin_texture.set_position(start_position);
    set_update_status(true);
}

void Coin::render(sf::RenderWindow& window)
{
    coin_texture.render(window);
}

void Coin::update()
{
    if(coin_texture.get_position().x <= 0)
    {
        std::clog << coin_texture.get_position().x << "  " << coin_texture.get_position().y << std::endl;
        coin_texture.set_position({start_position.x - 150, start_position.y});
    }

    //pipes_speed = 2
    coin_texture.set_position({coin_texture.get_position().x - 2, coin_texture.get_position().y});
}

Texture& Coin::get_texture()
{
    return coin_texture;
}

void Coin::catched(const sf::Vector2f& position)
{
    coin_sound.play();
    coin_texture.set_position(position);
}

Coin::~Coin()
{

}
