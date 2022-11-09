/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** EntityManager
*/

#include "EntityManager.hpp"

using namespace ecs;

EntityManager::EntityManager() : _entities(), _id(0) {}

EntityManager::~EntityManager() {}

void EntityManager::updateId() { _id++; }

Entity &EntityManager::createEntity()
{
    Entity *entity = new Entity(_id);
    std::shared_ptr<Entity> shEntity(entity);

    updateId();
    _entities.insert_or_assign(shEntity->getId(), std::move(shEntity));
    return (*entity);
}

Entity &EntityManager::getEntity(const size_t id)
{
    if (!_entities.contains(id))
        throw EntityNotExisting(_id, id);
    return (*_entities.at(id).get());
}

std::unordered_map<size_t, std::shared_ptr<Entity>> &EntityManager::getEntities() { return (_entities); }

void EntityManager::removeEntity(const size_t id)
{
    if (!_entities.contains(id))
        throw EntityNotExisting(_id, id);
    _entities.erase(id);
}

size_t EntityManager::getNumberEntities() const { return (_entities.size()); }
