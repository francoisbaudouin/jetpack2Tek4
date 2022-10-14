/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** main
*/

#include <iostream>
#include "ecs/Ecs.hpp"
#include "ecs/components/Position.hpp"
#include "ecs/components/Velocity.hpp"
#include "ecs/systems/Move.hpp"

using namespace ecs;

int main(void)
{
    Ecs ecs;
    auto &ent = ecs.createEntity();
    auto uEcs = std::make_shared<Ecs>(ecs);
    Move move(uEcs);

    ent.addComponent<Position>(0, 0);
    ent.addComponent<Velocity>(0, 0);
    move.run();
    return (0);
}
