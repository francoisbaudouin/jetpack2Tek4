/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Ecs
*/

#include "Ecs.hpp"
#include "exceptions/Exception.hpp"

using namespace ecs;

Ecs::Ecs() : _entities() {}

Ecs::~Ecs() { _entities.clear(); }

Entity &Ecs::createEntity()
{
    Entity entity;

    _entities.insert({entity.getId(), entity});
    return (_entities.at(entity.getId()));
}

Entity &Ecs::addEntity(const Entity &entity)
{
    if (_entities.contains(entity.getId()))
        throw EntityAlreadyExisting(entity.getId());
    _entities.insert({entity.getId(), entity});
    return (_entities.at(entity.getId()));
}

Entity &Ecs::getEntity(const size_t id)
{
    if (!_entities.contains(id))
        throw EntityAlreadyExisting(id);
    return (_entities.at(id));
}

void Ecs::removeEntity(const size_t id)
{
    if (!_entities.contains(id))
        throw EntityAlreadyExisting(id);
    _entities.erase(id);
}

size_t Ecs::getNumberEntities() const
{
  return (_entities.size());
}
