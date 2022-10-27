/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** ISystem
*/

#ifndef ISYSTEM_HPP_
#define ISYSTEM_HPP_

namespace ecs
{
    class ISystem {
      public:
        virtual ~ISystem() = default;
        virtual void run() = 0;
    };

} // namespace ecs

#endif /* !ISYSTEM_HPP_ */
