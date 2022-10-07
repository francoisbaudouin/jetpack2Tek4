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
        Velocity(const size_t entId, const float velX, const float velY);
        ~Velocity();

        void setVel(const float velX, const float velY);
        void setX(const float velX);
        void setY(const float velY);

        float getX() const;
        float getY() const;

      private:
        float _velX;
        float _velY;
    };
} // namespace ecs

#endif /* !Velocity_HPP_ */
