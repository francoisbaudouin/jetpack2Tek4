/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** SpritesMap
*/

#include "EntityMap.hpp"
#include <iostream>

EntityMap::EntityMap()
{

}

EntityMap::~EntityMap()
{
}

//member function

void EntityMap::display(sf::RenderWindow &window)
{
    for(std::pair<size_t, Entity> n : _entityMap) {
      window.draw(n.second);
    }
}
