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
        std::cout << entity1 << " and " << entity2 << " entities add coliding !" << std::endl;
}

void Collider::checkEntities(const std::unordered_map<size_t, std::shared_ptr<Entity>>::iterator &entity)
{
    auto iterator = entity;
    iterator++;
    while (iterator != _manager->getEntities().end()) {
        if (iterator->second->hasComponent<Position>() && iterator->second->hasComponent<HitBox>())
            this->compareEntities(entity->second->getId(), iterator->second->getId());
        iterator++;
    }
}

void Collider::run()
{
    for (auto entity = _manager->getEntities().begin(); entity != _manager->getEntities().end(); entity++) {
        if (entity->second->hasComponent<Position>() && entity->second->hasComponent<HitBox>())
            this->checkEntities(entity);
    }
}
