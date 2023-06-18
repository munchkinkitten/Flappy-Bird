#include <object.hpp>

std::vector<Object*> Object::objects;

Object::Object()
{
    objects.push_back(this);
}

void Object::update_all()
{
    for (std::size_t i = 0; i < objects.size(); i++) objects[i]->update();
}

void Object::render_all(sf::RenderWindow& window)
{
    for (std::size_t i = 0; i < objects.size(); i++) objects[i]->render(window);
}

Object::~Object()
{}
