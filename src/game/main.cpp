/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** main
*/

#include <iostream>
#include "ecs/Ecs.hpp"
#include "ecs/components/Position.hpp"

using namespace ecs;

int main(void)
{
    Ecs ecs;
    Entity entity;
    ecs.createEntity();
    ecs.addEntity(entity);
    std::cout << ecs.getNumberEntities() << std::endl;
    return (0);
}
