/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Entity
*/

#include "Entity.hpp"
#include <iostream>
#include "../components/IComponent.hpp"

using namespace ecs;

Entity::Entity(const size_t id) : _id(id) {}

Entity::~Entity() {}

size_t Entity::getId() { return (_id); }
