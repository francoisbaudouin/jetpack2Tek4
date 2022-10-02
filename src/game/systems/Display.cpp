/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Display
*/

#include "Display.hpp"
#include "../components/Drawable.hpp"
#include "../components/Position.hpp"

Display::Display() : _data() {}

Display::~Display() {}

void Display::clearData() { _data.clear(); }

void Display::addData(Entity &ent)
{
    if (!ent.hasComponent<Position>() || !ent.hasComponent<Drawable>())
        return;

    t_data data;
    Position &pos = ent.getComponent<Position>();
    data.pos = {pos.getX(), pos.getY()};
    data.id = ent.getId();
    _data.push_back(data);
}

std::vector<t_data> Display::getData() const { return (_data); }
