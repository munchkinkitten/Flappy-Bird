#include <bird.hpp>
#include <cmath>
#include <game.hpp>
#include <iostream>
#include <math_helpers.hpp>

static constexpr float default_G    = 0.3f;
static constexpr float bird_x_speed = 2.0f;

extern int frame;

Bird::Bird()
{
    for (int i = 1; i < 5; i++)
    {
        std::string filename = "resources/images/flap" + std::to_string(i) + ".png";
        textures.push_back(new Texture(filename.c_str()));
        auto origin = textures.back()->sizef() / 2.0f;
        textures.back()->set_origin(origin);
    }

    reset();
}

void Bird::render(sf::RenderWindow& window)
{
    get_texture().render(window);
    // Render box
//    sf::VertexArray lines(sf::LinesStrip, 4);
//    lines[0].position = get_texture().get_position();
//    lines[1].position = get_texture().get_position() + sf::Vector2f(get_texture().sizef().x, 0.f);
//    lines[2].position = get_texture().get_position() + get_texture().sizef();
//    lines[3].position = get_texture().get_position() + sf::Vector2f(0.f, get_texture().sizef().y);
//    window.draw(lines);
}

void Bird::update()
{
    if (frame % 10 == 0)
    {
        set_next_texture();
    }

    speed = std::min(speed + G, max_speed);

    set_rotation_angle();

    get_texture().set_position({get_texture().get_position().x, get_texture().get_position().y + speed});

    if (get_texture().get_position().y + get_texture().size().y > Game::instance().get_window().getSize().y)
    {
        G     = 0.f;
        speed = 0;
        Game::instance().game_over();
    }
    else if (get_texture().get_position().y < 0)
    {
        get_texture().set_position({get_texture().get_position().x, 0});
        speed = 0;
    }
    else if (G == 0.0f)
    {
        G = default_G;
    }
}

void Bird::reset()
{
    texture_index = 0;
    get_texture().set_position({200, 200});
    G     = default_G;
    speed = 0.0;
    jump();
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

static float dot(const sf::Vector2f& vec1, const sf::Vector2f& vec2)
{
    float a = vec1.x * vec2.x + vec1.y * vec2.y;
    float b = length(vec1) * length(vec2);
    return a / b;
}

float radiand_to_degrees(float radians)
{
    return radians * (180.0f / M_PI);
}

void Bird::set_rotation_angle()
{
    static const sf::Vector2f OX = {1.0, 0.0};

    auto current_pos   = get_texture().get_position();
    auto next_position = current_pos + sf::Vector2f(bird_x_speed, speed);
    auto move_vector   = next_position - current_pos;

    float tmp_angle = radiand_to_degrees(std::acos(dot(OX, move_vector)));

    if (speed < 0)
    {
        tmp_angle = -tmp_angle;
    }

    angle = angle * 0.95 + tmp_angle * 0.05;


    get_texture().set_rotation(angle);
}

void Bird::set_next_texture()
{
    size_t next_index = (texture_index + 1) % textures.size();

    sf::Vector2f position = textures[texture_index]->get_position();
    textures[next_index]->set_position(position);
    texture_index = next_index;
}

Texture& Bird::get_texture()
{
    return *textures[texture_index];
}

void Bird::jump()
{
    speed = -6.5;
}


Bird::~Bird()
{
    for(Texture* texture : textures)
        delete texture;
}
