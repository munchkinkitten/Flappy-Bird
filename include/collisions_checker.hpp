#pragma once

#include <list>
#include <texture.hpp>
#include <object.hpp>
#include <bird.hpp>
#include <pipe.hpp>

class Pipe;
class Bird;

class CollisionsChecker : public Object
{
private:
    Bird* bird;
    std::list<Pipe*>& pipes_list;

public:
    CollisionsChecker(Bird* bird, std::list<Pipe*>& pipes_list);

    void update();

    void render(sf::RenderWindow& window);

    bool check_collisions();
};
