#pragma once

#include <SFML/Graphics.hpp>

extern std::size_t hole_height;
extern std::size_t half_hole_height;

class Pipe
{
private:
    sf::Sprite top;
    sf::Sprite bottom;
    sf::Vector2f position;
    bool completed = false;

public:
    Pipe(const sf::Texture& texture, sf::Vector2f position);

    void render(sf::RenderWindow& window);

    const sf::Vector2f& get_position();

    inline const sf::Sprite& get_top() const
    {
        return top;
    }

    inline const sf::Sprite& get_bottom() const
    {
        return bottom;
    }

    inline void set_complete(bool flag = true)
    {
        completed = flag;
    }

    inline bool is_completed()
    {
        return completed;
    }

    void set_position(sf::Vector2f pos);
};
