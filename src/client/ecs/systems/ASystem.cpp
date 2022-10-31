/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** ASystem
*/

#include "ASystem.hpp"

using namespace ecs;

ASystem::ASystem(std::shared_ptr<Ecs> &manager) : _manager(manager) {}

ASystem::~ASystem() {}

void ASystem::run(const size_t sceneId) { static_cast<void>(sceneId); }
