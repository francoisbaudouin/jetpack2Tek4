/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Entity
*/

#include "Entity.hpp"
#include "../components/IComponent.hpp"

using namespace ecs;

Entity::Entity(const size_t id) : _id(id) {}

Entity::~Entity()
{
    while (_components.size() > 0) {
        if (_components.begin()->second)
            delete _components.begin()->second;
        _components.erase(_components.begin()->first);
    }
}

size_t Entity::getId() const { return (_id); }

void Entity::setId(const size_t id) { _id = id; }
