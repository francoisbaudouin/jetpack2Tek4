/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Entity
*/

#include "Entity.hpp"
#include <iostream>
#include "../components/IComponent.hpp"

using namespace ecs;

size_t getNewEntityId()
{
    static size_t id = 0;
    return (id++);
}

Entity::Entity() : _id(getNewEntityId()) {}

Entity::~Entity()
{
    while (_components.size() > 0) {
        delete _components.begin()->second;
        _components.erase(_components.begin()->first);
    }
}

size_t Entity::getId() const { return (_id); }
