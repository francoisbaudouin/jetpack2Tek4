/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** EntityGenerator
*/

#ifndef ENTITYGENERATOR_HPP_
#define ENTITYGENERATOR_HPP_

#include <vector>

#include "EntityManager.hpp"

namespace ecs
{
    class EntityGenerator {
      public:
        EntityGenerator();
        ~EntityGenerator();

        void addComponent(Entity &entity, const std::string &component);

        size_t createEntity(EntityManager &manager, const std::string &type);
    };
} // namespace ecs

#endif /* !ENTITYGENERATOR_HPP_ */
