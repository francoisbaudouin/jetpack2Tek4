/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** ASystem
*/

#include "ASystem.hpp"

using namespace ecs;

ASystem::ASystem(std::shared_ptr<Ecs> &entityMap) : _entityMap(entityMap) {}

ASystem::~ASystem() {}

void ASystem::run() {}
