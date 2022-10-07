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

Move::Move(const std::unordered_map<size_t, std::shared_ptr<ecs::Entity>> &entityMap) { _entityMap = entityMap; }

Move::~Move() {}

void Move::applyVelocity(std::shared_ptr<ecs::Entity> &entity)
{
    auto &velocity = entity->getComponent<Velocity>();
    auto &position = entity->getComponent<Position>();

    position.setX(position.getX() + velocity.getX());
    position.setY(position.getY() + velocity.getY());
}

void Move::run()
{
    auto it = _entityMap.begin();

    while (it != _entityMap.end()) {
        if (it->second->hasComponent<Velocity>() && it->second->hasComponent<Position>())
            this->applyVelocity(it->second);
        it++;
    }
}