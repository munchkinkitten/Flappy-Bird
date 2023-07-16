#pragma once

#include <object.hpp>
#include <texture.hpp>
//#include <SFML/Graphics.hpp>
//#include <vector>

class ScoreCounter : public Object
{
private:
    int score = 0;
    int helper_x = 0, helper_y = 0;
    float bird_x_position;
    const int sprite_width = 70;
    const int sprite_height = 102;
    const int space = 32;
    sf::Texture num_texture;
    std::vector <sf::Sprite> sprites_vec;

public:
    ScoreCounter();

    inline void reset()
    {
        score = 0;
    }

    void update();
    void render(sf::RenderWindow& window);
};
