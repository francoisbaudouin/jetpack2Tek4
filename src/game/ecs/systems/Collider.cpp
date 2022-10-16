/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Collider
*/

#include "Collider.hpp"
#include <iostream>
#include "../components/HitBox.hpp"
#include "../components/Position.hpp"
#include "ColliderReaction.hpp"

using namespace ecs;

Collider::Collider(std::shared_ptr<Ecs> &manager) : ASystem(manager) {}

Collider::~Collider() {}

void Collider::compareEntities(const size_t entity1, const size_t entity2)
{
    Position &position1 = _manager->getEntity(entity1).getComponent<Position>();
    Position &position2 = _manager->getEntity(entity2).getComponent<Position>();
    HitBox &size1 = _manager->getEntity(entity1).getComponent<HitBox>();
    HitBox &size2 = _manager->getEntity(entity2).getComponent<HitBox>();

    if (position1.getX() < position2.getX() + size2.getX() && position1.getX() + size1.getX() > position2.getX()
        && position1.getY() < position2.getY() + size2.getY() && position1.getY() + size1.getY() > position2.getY())
        _manager->getSystem<ColliderReaction>().run(entity1, entity2);
}

void Collider::checkEntities(const std::unordered_map<size_t, std::shared_ptr<Entity>>::iterator &entity)
{
    auto iterator = entity;
    size_t entityId = entity->first;
    size_t iteratorId;

    iterator++;
    while (iterator != _manager->getEntities().end()) {
        iteratorId = iterator->first;
        if (iterator->second->hasComponent<Position>() && iterator->second->hasComponent<HitBox>())
            this->compareEntities(entity->second->getId(), iterator->second->getId());
        std::cout << "collide/check:" << _manager->getNumberEntities() << std::endl;
        if (!_manager->getEntities().contains(entityId) || !_manager->getEntities().contains(iteratorId))
            break;
        iterator++;
    }
}

void Collider::run()
{
    size_t entityId;

    for (auto entity = _manager->getEntities().begin(); entity != _manager->getEntities().end(); entity++) {
        entityId = entity->first;
        if (entity->second->hasComponent<Position>() && entity->second->hasComponent<HitBox>())
            this->checkEntities(entity);
        std::cout << "collide:" << _manager->getNumberEntities() << std::endl;
        if (!_manager->getEntities().contains(entityId)) {
            while (!_manager->getEntities().contains(entityId)) {
                if (entityId == 0)
                    return;
                entityId--;
            }
            entity = _manager->getEntities().find(entityId);
        }
    }
}
