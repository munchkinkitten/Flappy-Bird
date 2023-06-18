#include <bird.hpp>
#include <game.hpp>

Bird::Bird()
{
    bird_texture.open("resources/images/flap1.png");
    bird_texture.set_position({200, 200});
}

void Bird::render(sf::RenderWindow& window)
{
    bird_texture.render(window);
}

void Bird::update()
{
    speed = std::min(speed + G, max_speed);
    bird_texture.set_position({bird_texture.get_position().x, bird_texture.get_position().y + speed});

    if (bird_texture.get_position().y > Game::instance().get_window().getSize().y - 30)
    {
        G     = 0.f;
        speed = 0;
    }
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

void Bird::jump()
{
    speed = -8;
}
