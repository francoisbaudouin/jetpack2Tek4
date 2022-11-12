/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Stat
*/

#include "Stat.hpp"

using namespace ecs;

Stat::Stat(const size_t entityId, const size_t health) : AComponent(entityId), _health(health) {}

Stat::~Stat() {}

size_t Stat::getHealth() const { return (_health); }

void Stat::setHealth(const size_t health) { _health = health; }