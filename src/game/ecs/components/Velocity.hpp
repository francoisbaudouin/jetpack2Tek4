/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Velocity
*/

#ifndef Velocity_HPP_
#define Velocity_HPP_

#include "AComponent.hpp"

namespace ecs
{
    class Velocity : public AComponent {
      public:
        Velocity(const size_t entityId, const float velocityX, const float velocityY);
        ~Velocity();

        void setVel(const float velocityX, const float velocityY);
        void setX(const float velocityX);
        void setY(const float velocityY);

        float getX() const;
        float getY() const;

      private:
        float _velocityX;
        float _velocityY;
    };
} // namespace ecs

#endif /* !Velocity_HPP_ */
