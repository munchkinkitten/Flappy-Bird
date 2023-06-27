#pragma once
#include <vector>
#include <SFML/Graphics.hpp>


class Object
{

    bool m_update_active = true;

public:
    static std::vector<Object*> objects;

    Object();

    void set_update_status(bool active);

    virtual void update()                         = 0;
    virtual void render(sf::RenderWindow& window) = 0;
    static void update_all();
    static void render_all(sf::RenderWindow& window);
    virtual ~Object();
};
