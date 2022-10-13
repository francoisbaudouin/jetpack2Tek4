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
        /**
         * @brief Construct a new Velocity object
         *
         * @param entityId : ID of the entity using this component
         * @param velocityX : velocity on the X axis
         * @param velocityY : velocity on the Y axis
         */
        Velocity(const size_t entityId, const float velocityX, const float velocityY);
        /**
         * @brief Destroy the Velocity object
         *
         */
        ~Velocity();

        /**
         * @brief Set the Velocity object
         *
         * @param velocityX : velocity on the X axis
         * @param velocityY : velocity on the Y axis
         */
        void setVelocity(const float velocityX, const float velocityY);
        /**
         * @brief Set the velocity on the X axis
         *
         * @param velocityX : velocity on the X axis
         */
        void setX(const float velocityX);
        /**
         * @brief Set the velocity on the Y axis
         *
         * @param velocityY : velocity on the Y axis
         */
        void setY(const float velocityY);

        /**
         * @brief Get the velocity on the X axis
         *
         * @return float
         */
        float getX() const;
        /**
         * @brief Get the velocity on the Y axis
         *
         * @return float
         */
        float getY() const;

      private:
        float _velocityX;
        float _velocityY;
    };
} // namespace ecs

#endif /* !Velocity_HPP_ */
