/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Velocity
*/

#ifndef VELOCITY_HPP_
#define VELOCITY_HPP_

#include "AComponent.hpp"

namespace ecs
{
    class Velocity : public AComponent {
      public:
        Velocity();
        Velocity(float velocity);
        ~Velocity();

      protected:
        float _velocity;
    };
} // namespace ecs

#endif /* !VELOCITY_HPP_ */
