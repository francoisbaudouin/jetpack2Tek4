/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** ISystem
*/

#ifndef ISYSTEM_HPP_
#define ISYSTEM_HPP_

#include <cstddef>

namespace ecs
{
    class ISystem {
      public:
        virtual ~ISystem() = default;
        virtual void run(const std::string &sceneName) = 0;
    };

} // namespace ecs

#endif /* !ISYSTEM_HPP_ */
