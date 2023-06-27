#include <bird.hpp>
#include <game.hpp>

static constexpr float default_G = 0.3f;

Bird::Bird()
{
    bird_texture.open("resources/images/flap1.png");
    reset();
}

void Bird::render(sf::RenderWindow& window)
{
    bird_texture.render(window);
}

void Bird::update()
{
    speed = std::min(speed + G, max_speed);

    bird_texture.set_position({bird_texture.get_position().x, bird_texture.get_position().y + speed});

    if (bird_texture.get_position().y + bird_texture.size().y > Game::instance().get_window().getSize().y)
    {
        G     = 0.f;
        speed = 0;
        Game::instance().game_over();
    }
    else if (bird_texture.get_position().y < 0)
    {
        bird_texture.set_position({bird_texture.get_position().x, 0});
        speed = 0;
    }
    else if (G == 0.0f)
    {
        G = default_G;
    }
}

void Bird::reset()
{
    bird_texture.set_position({200, 200});
    G     = default_G;
    speed = 0.0;
}

void Bird::check_event(const sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Key::Space)
        {
            jump();
        }
    }
}

Texture& Bird::get_texture()
{
    return bird_texture;
}

void Bird::jump()
{
    speed = -7;
}
