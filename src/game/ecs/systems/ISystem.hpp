/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** ISystem
*/

#ifndef ISYSTEM_HPP_
#define ISYSTEM_HPP_
#include "../entity/Entity.hpp"
#include <unordered_map>

namespace ecs
{
    class ISystem {
      public:
        virtual ~ISystem() = default;
        virtual void update(std::unordered_map<size_t, ecs::Entity> &entityVector) = 0;
    };

} // namespace ecs

#endif /* !ISYSTEM_HPP_ */
