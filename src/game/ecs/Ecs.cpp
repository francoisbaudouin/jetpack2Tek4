/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Ecs
*/

#include "Ecs.hpp"
#include "exceptions/Exception.hpp"


using namespace ecs;

Ecs::Ecs() : _entities(), _systems() {}

Ecs::~Ecs() { _entities.clear(); }

Entity &Ecs::createEntity()
{
    Entity *entity = new Entity();
    std::shared_ptr<Entity> shEntity(entity);

    _entities.insert_or_assign(shEntity->getId(), std::move(shEntity));
    return (*entity);
}

Entity &Ecs::addEntity(const Entity &entity)
{
    if (_entities.contains(entity.getId()))
        throw EntityAlreadyExisting(entity.getId());
    _entities.insert_or_assign(entity.getId(), std::move(std::make_shared<Entity>(entity)));
    return (*_entities.at(entity.getId()).get());
}

Entity &Ecs::getEntity(const size_t id)
{
    if (!_entities.contains(id))
        throw EntityAlreadyExisting(id);
    return (*_entities.at(id).get());
}

std::unordered_map<size_t, std::shared_ptr<Entity>> &Ecs::getEntities() { return (_entities); }

void Ecs::removeEntity(const size_t id)
{
    if (!_entities.contains(id))
        throw EntityAlreadyExisting(id);
    _entities.erase(id);
}

size_t Ecs::getNumberEntities() const { return (_entities.size()); }

void Ecs::clearSystems()
{
    while (_systems.size() > 0) {
        delete _systems.begin()->second;
        _systems.erase(_systems.begin()->first);
    }
}
