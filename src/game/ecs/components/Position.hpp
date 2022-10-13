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
        /**
         * @brief Construct a new Position object
         *
         * @param entityId : ID of the entity using this component
         * @param positionX : position on the X axis
         * @param positionY : position on the Y axis
         */
        Position(const size_t entityId, const float positionX, const float positionY);
        /**
         * @brief Destroy the Position object
         *
         */
        ~Position();

        /**
         * @brief Set the Position object
         *
         * @param positionX : position on the X axis
         * @param positionY : position on the Y axis
         */
        void setPosition(const float positionX, const float positionY);
        /**
         * @brief Set the position on the X axis
         *
         * @param positionX : position on the X axis
         */
        void setX(const float positionX);
        /**
         * @brief Set the position on the Y axis
         *
         * @param positionY : position on the Y axis
         */
        void setY(const float positionY);

        /**
         * @brief Get the position on the X axis
         *
         * @return float : position on concerned axis
         */
        float getX() const;
        /**
         * @brief Get the position on the Y axis
         *
         * @return float : position on concerned axis
         */
        float getY() const;

      private:
        float _positionX;
        float _positionY;
    };
} // namespace ecs

#endif /* !POSITION_HPP_ */
