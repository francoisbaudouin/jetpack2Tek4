/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** EntityGenerator
*/

#ifndef ENTITYGENERATOR_HPP_
#define ENTITYGENERATOR_HPP_

#include "Entity.hpp"

namespace ecs
{
    class EntityGenerator {
      public:
        EntityGenerator();
        ~EntityGenerator();


        Entity &generatePlayer() const;

      private:
    };
} // namespace ecs

#endif /* !ENTITYGENERATOR_HPP_ */
