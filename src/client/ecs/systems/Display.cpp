/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Display
*/

#include "Display.hpp"

using namespace ecs;

Display::Display(std::shared_ptr<Ecs> &manager) : ASystem(manager) {}

Display::~Display() {}

void Display::run(sf::RenderWindow &window)
{
    if (_manager->getNumberEntities() == 0)
        return;
    for (auto &entity : _manager->getEntities()) {
        if (entity.second->hasComponent<Drawable>() && entity.second->hasComponent<Position>()) {
            Drawable &drawable = entity.second->getComponent<Drawable>();
            Position &position = entity.second->getComponent<Position>();
            drawable.getSprite().setPosition(position.getX(), position.getY());
            window.draw(drawable.getSprite());
        }
    }
}
