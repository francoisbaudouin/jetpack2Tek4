/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Ecs
*/

#include "Ecs.hpp"
#include "exceptions/Exception.hpp"

using namespace ecs;

Ecs::Ecs() : _entityManagers(), _systems() {}

Ecs::~Ecs()
{
    this->clearEntityManagers();
    this->clearSystems();
}

EntityManager &Ecs::createEntityManager(const size_t sceneId)
{
    EntityManager *manager;

    if (_entityManagers.contains(sceneId))
      throw EntityManagerAlreadyExisting(sceneId);
    manager = new EntityManager();
    _entityManagers.insert({sceneId, manager});
    return (*manager);
}

EntityManager &Ecs::getEntityManager(const size_t sceneId)
{
    if (!_entityManagers.contains(sceneId))
      throw EntityManagerNotExisting(sceneId);
    return (*_entityManagers.at(sceneId));
}

void Ecs::clearEntityManagers()
{
    while (_entityManagers.size() > 0) {
        if (_entityManagers.begin()->second)
            delete _entityManagers.begin()->second;
        _entityManagers.erase(_entityManagers.begin()->first);
    }
}

void Ecs::clearSystems()
{
    while (_systems.size() > 0) {
        if (_systems.begin()->second)
            delete _systems.begin()->second;
        _systems.erase(_systems.begin()->first);
    }
}
