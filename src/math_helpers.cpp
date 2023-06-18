#include <math_helpers.hpp>
#include <cmath>

float length(const sf::Vector2f& vector)
{
    return std::sqrt(vector.x * vector.x + vector.y * vector.y);
}

sf::Vector2f normalize(const sf::Vector2f& vector)
{
    float l = length(vector);
    if (l == 0.0)
    {
        return sf::Vector2f(0.0f, 0.0f);
    }
    return vector / l;
}

