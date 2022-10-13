/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** EntityGenerator
*/

#include "EntityGenerator.hpp"
#include "../components/Position.hpp"

using namespace ecs;

EntityGenerator::EntityGenerator() {}

EntityGenerator::~EntityGenerator() {}

Entity &EntityGenerator::generatePlayer() const
{
  Entity entity;

  entity.addComponent<Position>(0, 0);
}