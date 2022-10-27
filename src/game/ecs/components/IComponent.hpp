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

        virtual size_t getEntityId() const = 0;
        virtual void setEntityId(const size_t entityId) = 0;

      private:
    };
} // namespace ecs

#endif /* !ICOMPONENT_HPP_ */
