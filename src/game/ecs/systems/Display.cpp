/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Display
*/

#include "Display.hpp"
#include "../components/Drawable.hpp"
#include "../components/Position.hpp"

#include <iostream>

using namespace ecs;

Display::Display(std::unordered_map<size_t, std::shared_ptr<ecs::Entity>> &entityMap) : ASystem(entityMap) {}

Display::~Display() {}

void Display::run(sf::RenderWindow &window)
{
    if (_entityMap.size() == 0) {
        return;
    }
    for (auto entity : _entityMap) {
        if (entity.second->hasComponent<Drawable>() && entity.second->hasComponent<Position>()) {
            Drawable &drawable = entity.second->getComponent<Drawable>();
            Position &position = entity.second->getComponent<Position>();
            drawable.getSprite().setPosition(position.getX(), position.getY());
            window.draw(drawable.getSprite());
        }
    }
}
