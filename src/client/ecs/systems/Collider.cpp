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

void Collider::compareEntities(const size_t sceneId, const size_t entity1, const size_t entity2)
{
    Position &position1 = _manager->getEntityManager(sceneId).getEntity(entity1).getComponent<Position>();
    Position &position2 = _manager->getEntityManager(sceneId).getEntity(entity2).getComponent<Position>();
    HitBox &size1 = _manager->getEntityManager(sceneId).getEntity(entity1).getComponent<HitBox>();
    HitBox &size2 = _manager->getEntityManager(sceneId).getEntity(entity2).getComponent<HitBox>();

    if (position1.getX() < position2.getX() + size2.getX() && position1.getX() + size1.getX() > position2.getX()
        && position1.getY() < position2.getY() + size2.getY() && position1.getY() + size1.getY() > position2.getY())
        _manager->getSystem<ColliderReaction>().run(sceneId, entity1, entity2);
}

void Collider::checkEntities(
    const size_t sceneId, const std::unordered_map<size_t, std::shared_ptr<Entity>>::iterator &entity)
{
    auto iterator = entity;
    size_t entityId = entity->first;
    size_t iteratorId;

    iterator++;
    while (iterator != _manager->getEntityManager(sceneId).getEntities().end()) {
        iteratorId = iterator->first;
        if (iterator->second->hasComponent<Position>() && iterator->second->hasComponent<HitBox>())
            this->compareEntities(sceneId, entity->second->getId(), iterator->second->getId());
        if (!_manager->getEntityManager(sceneId).getEntities().contains(entityId)
            || !_manager->getEntityManager(sceneId).getEntities().contains(iteratorId))
            break;
        iterator++;
    }
}

void Collider::run(const size_t sceneId)
{
    size_t entityId;

    for (auto entity = _manager->getEntityManager(sceneId).getEntities().begin();
         entity != _manager->getEntityManager(sceneId).getEntities().end(); entity++) {
        entityId = entity->first;
        if (entity->second->hasComponent<Position>() && entity->second->hasComponent<HitBox>())
            this->checkEntities(sceneId, entity);
        if (!_manager->getEntityManager(sceneId).getEntities().contains(entityId)) {
            return;
            while (!_manager->getEntityManager(sceneId).getEntities().contains(entityId)) {
                if (entityId == 0)
                    return;
                entityId--;
            }
            entity = _manager->getEntityManager(sceneId).getEntities().find(entityId);
        }
    }
}
