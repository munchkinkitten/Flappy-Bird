#include <collisions_checker.hpp>
#include <game.hpp>


static bool check_collision(const sf::Vector2f& pos1, const sf::Vector2f& size1, const sf::Vector2f& pos2,
                            const sf::Vector2f& size2)
{
    auto a = std::abs((pos1.x + size1.x / 2) - (pos2.x + size2.x / 2)) * 2 < (size1.x + size2.x);
    auto b = std::abs((pos1.y + size1.y / 2) - (pos2.y + size2.y / 2)) * 2 < (size1.y + size2.y);

    return (a) && (b);
}


CollisionsChecker::CollisionsChecker(Bird* bird, std::list<Pipe*>& pipes_list, Coin* coin) : bird(bird), pipes_list(pipes_list), coin(coin)
{}

void CollisionsChecker::update()
{
    if (check_collisions())
    {
        Game::instance().game_over();
    }
}

void CollisionsChecker::render(sf::RenderWindow& window)
{}


static sf::Vector2f to_vector_2f(const sf::Vector2u& vec)
{
    return sf::Vector2f(vec.x, vec.y);
}

bool CollisionsChecker::check_collisions()
{
    if (coin->get_texture().get_position().x - 0.5 * coin->get_texture().size().x <=
                bird->get_texture().get_position().x &&
        coin->get_texture().get_position().x + 1.5 * coin->get_texture().size().x >=
                bird->get_texture().get_position().x &&
        coin->get_texture().get_position().y - 0.5 * coin->get_texture().size().y <=
                bird->get_texture().get_position().y &&
        coin->get_texture().get_position().y + 1.5 * coin->get_texture().size().y >=
                bird->get_texture().get_position().y)
    {
        coin->catched({pipes_list.back()->get_position().x + pipes_list.back()->get_bottom().getTexture()->getSize().x + 100 - coin->get_texture().size().x / 2, coin->get_texture().get_position().y});
    }

        int count = 0;

    for (auto& pipe : pipes_list)
    {
        if (++count > 2)
            break;

        auto p1 = bird->get_texture().get_position();
        auto s1 = bird->get_texture().sizef();

        auto p2 = pipe->get_bottom().getPosition();
        auto s2 = to_vector_2f(pipe->get_bottom().getTexture()->getSize());

        auto p3 = pipe->get_top().getPosition();
        auto s3 = to_vector_2f(pipe->get_top().getTexture()->getSize());
        p3.x -= s3.x;
        p3.y -= s3.y;

        if (check_collision(p1, s1, p2, s2) || check_collision(p1, s1, p3, s3))
        {
            return true;
        }
    }


    return false;
}
