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
    auto &ent = ecs.createEntity();
    std::cout << "test" << std::endl;
    ecs.addEntity(entity);
    std::cout << "test" << std::endl;

    ent.addComponent<Position>(0, 0);
    std::cout << "test" << std::endl;

    auto &ent2 = ecs.getEntity(ent.getId());
    std::cout << "test" << std::endl;

    std::cout << ent2.hasComponent<Position>() << std::endl;
    std::cout << "test" << std::endl;
    return (0);
}
