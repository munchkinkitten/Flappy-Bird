#pragma once

#include <list>
#include <texture.hpp>
#include <object.hpp>
#include <bird.hpp>
#include <pipe.hpp>
#include <coin.hpp>

class Pipe;
class Bird;
class Coin;

class CollisionsChecker : public Object
{
private:
    Bird* bird;
    std::list<Pipe*>& pipes_list;
    Coin* coin;


public:
    CollisionsChecker(Bird* bird, std::list<Pipe*>& pipes_list, Coin* coin);

    void update();
    void coin_catched();
    void render(sf::RenderWindow& window);
    bool check_collisions();
};
