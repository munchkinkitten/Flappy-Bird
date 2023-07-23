#include <score_counter.hpp>
#include <bird.hpp>
#include <pipe_controller.hpp>
#include <game.hpp>
#include <pipe.hpp>

ScoreCounter::ScoreCounter()
{
    num_texture.loadFromFile("resources/images/numbers.png");
    bird_x_position = Game::instance().get_bird()->get_texture().get_position().x;
    for (int i = 0; i < 10; i++)
    {
        sf::Sprite spr;
        spr.setScale({0.5, 0.5});
        spr.setTexture(num_texture);
        sf::IntRect rect(helper_x, helper_y, sprite_width, sprite_height);
        spr.setTextureRect(rect);

        helper_x += sprite_width + space;

        sprites_vec.push_back(spr);
    }
}

void ScoreCounter::update()
{
    auto& pipes = Game::instance().get_pipe_controller()->get_pipes_list();

    if (pipes.empty())
    {
        return;
    }

    auto pipe_pos = pipes.front()->get_position().x + pipes.front()->get_bottom().getTextureRect().width;
    if (bird_x_position >= pipe_pos && !pipes.front()->is_completed())
    {
        score++;
        pipes.front()->set_complete(true);
    }
}

void ScoreCounter::render(sf::RenderWindow& window)
{
    std::string number = std::to_string(score);
    // num = '2' -> 2
    int offset = 20;
    for (std::size_t i = 0; i < number.length(); i++)
    {
        int index = number[i] - '0';
        sprites_vec[index].setPosition({float(offset), 0});
        window.draw(sprites_vec[index]);
        offset += sprite_width * 0.6;
    }
}

