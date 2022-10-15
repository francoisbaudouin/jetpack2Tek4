/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** HitBox
*/

#ifndef HitBox_HPP_
#define HitBox_HPP_

#include "AComponent.hpp"

namespace ecs
{
    class HitBox : public AComponent {
      public:
        /**
         * @brief Construct a new HitBox object
         *
         * @param entityId : ID of the entity using this component
         * @param sizeX : size on the X axis
         * @param sizeY : size on the Y axis
         */
        HitBox(const size_t entityId, const float sizeX, const float sizeY);
        /**
         * @brief Destroy the HitBox object
         *
         */
        ~HitBox();

        /**
         * @brief Set the HitBox object
         *
         * @param sizeX : size on the X axis
         * @param sizeY : size on the Y axis
         */
        void setHitBox(const float sizeX, const float sizeY);
        /**
         * @brief Set the size on the X axis
         *
         * @param sizeX : size on the X axis
         */
        void setX(const float sizeX);
        /**
         * @brief Set the size on the Y axis
         *
         * @param sizeY : size on the Y axis
         */
        void setY(const float sizeY);

        /**
         * @brief Get the size on the X axis
         *
         * @return float : size on concerned axis
         */
        float getX() const;
        /**
         * @brief Get the size on the Y axis
         *
         * @return float : size on concerned axis
         */
        float getY() const;

      private:
        float _sizeX;
        float _sizeY;
    };
} // namespace ecs

#endif /* !HitBox_HPP_ */
