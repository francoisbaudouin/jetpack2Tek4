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
    Velocity &velocity = entity->getComponent<Velocity>();
    Position &position = entity->getComponent<Position>();

    position.setX(position.getX() + velocity.getX());
    position.setY(position.getY() + velocity.getY());
}

void Move::run()
{
    auto iterator = _entityMap.begin();

    while (iterator != _entityMap.end()) {
        if (iterator->second->hasComponent<Velocity>() && iterator->second->hasComponent<Position>())
            this->applyVelocity(iterator->second);
        iterator++;
    }
}