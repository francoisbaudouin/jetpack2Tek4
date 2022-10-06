/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** ASystem
*/

#ifndef ASYSTEM_HPP_
#define ASYSTEM_HPP_
#include <unordered_map>
#include "../entity/Entity.hpp"

namespace ecs
{
    class ASystem {
      public:
        ASystem();
        ~ASystem();

      protected:
        std::unordered_map<size_t, ecs::Entity> _entityMap;
      private:
    };
} // namespace ecs

#endif /* !ASYSTEM_HPP_ */
