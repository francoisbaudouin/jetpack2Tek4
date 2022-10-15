/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Type
*/

#include "Type.hpp"

using namespace ecs;

Type::Type(entityType type) : _type(type) {}

Type::~Type() {}

entityType Type::getEntityType() const { return _type; }
