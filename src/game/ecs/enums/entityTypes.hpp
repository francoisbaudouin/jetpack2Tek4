/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** types
*/

#ifndef TYPES_HPP_
#define TYPES_HPP_

namespace ecs
{
    enum entityType {
        UNDEFINED_ENTITY_TYPE = -1,
        PLAYER = 0,
        ENEMY,
        PROJECTILE,
        WALL
    };
} // namespace ecs

#endif /* !TYPES_HPP_ */
