/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Controllable
*/

#ifndef CONTROLLABLE_HPP_
#define CONTROLLABLE_HPP_

#include "AComponent.hpp"

namespace ecs
{
    class Controllable : public AComponent {
      public:
        Controllable();
        ~Controllable();
        bool _isControllable;

      protected:
      private:
    };
} // namespace ecs

#endif /* !CONTROLLABLE_HPP_ */
