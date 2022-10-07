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
        Position(const size_t entId, const float posX, const float posY);
        ~Position();

        void setPos(const float posX, const float posY);
        void setX(const float posX);
        void setY(const float posY);

        float getX() const;
        float getY() const;

      private:
        float _posX;
        float _posY;
    };
} // namespace ecs

#endif /* !POSITION_HPP_ */
