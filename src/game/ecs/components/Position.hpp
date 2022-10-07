/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Position
*/

#ifndef POSITION_HPP_
#define POSITION_HPP_

#include "AComponent.hpp"

namespace ecs
{
    class Position : public AComponent {
      public:
        Position(const size_t entityId, const float positionX, const float positionY);
        ~Position();

        void setPosition(const float positionX, const float positionY);
        void setX(const float positionX);
        void setY(const float positionY);

        float getX() const;
        float getY() const;

      private:
        float _positionX;
        float _positionY;
    };
} // namespace ecs

#endif /* !POSITION_HPP_ */
