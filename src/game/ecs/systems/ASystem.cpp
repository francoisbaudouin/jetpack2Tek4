/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** ASystem
*/

#include "ASystem.hpp"
#include <iostream>
using namespace ecs;


ASystem::ASystem(std::unordered_map<size_t, std::shared_ptr<ecs::Entity>> &entityMap) : _entityMap(entityMap)
{
}


ASystem::~ASystem() {}

void ASystem::run() {}
