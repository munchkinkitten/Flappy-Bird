#pragma once
#include <texture.hpp>
#include <object.hpp>

class Background : public Object
{
    Texture image_1;
    Texture image_2;
    int speed = 1;

public:
    Background(const char* path);

    void update() override;
    void render(sf::RenderWindow& window) override;
};
