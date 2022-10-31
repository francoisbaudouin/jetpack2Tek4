/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Move
*/

#include "Move.hpp"
#include "../components/Position.hpp"
#include "../components/Velocity.hpp"

using namespace ecs;

Move::Move(std::shared_ptr<Ecs> &manager) : ASystem(manager) {}

Move::~Move() {}

void Move::applyVelocity(Entity &entity)
{
    Velocity &velocity = entity.getComponent<Velocity>();
    Position &position = entity.getComponent<Position>();

    position.setX(position.getX() + velocity.getX());
    position.setY(position.getY() + velocity.getY());
}

void Move::run(const size_t sceneId)
{
    for (auto &entity : _manager->getEntityManager(sceneId).getEntities()) {
        if (entity.second->hasComponent<Position>() && entity.second->hasComponent<Velocity>())
            this->applyVelocity(_manager->getEntityManager(sceneId).getEntity(entity.first));
    }
}
