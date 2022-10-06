/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include <string>

namespace ecs
{
    class IComponent {
      public:
        virtual ~IComponent() = default;
        virtual std::string getName() const = 0;

      private:
    };
} // namespace ecs

#endif /* !ICOMPONENT_HPP_ */
