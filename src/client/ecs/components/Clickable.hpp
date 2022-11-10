/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Clickable
*/

#ifndef CLICKABLE_HPP_
#define CLICKABLE_HPP_

#include "AComponent.hpp"

namespace ecs
{
    class Clickable : public AComponent {
      public:
        Clickable(const size_t entityId);
        ~Clickable();
        /**
         * @brief heck if the clickable is hovered
         *
         * @return true if hovered
         * @return false if not hovered
         */
        bool isHovered() const;
        /**
         * @brief check if the clickable is clicked
         *
         * @return true if is clicked
         * @return false if not clicked
         */
        bool isClicked() const;
        /**
         * @brief set the Clicked state of the component to the bool passed in parameter
         *
         * @param isClicked the state will change to the isClicked parameter
         */
        void setClicked(const bool isClicked);
        /**
         * @brief set the hovered state of the component to the bool passed in parameter
         *
         * @param isHovered the state will change to the isHovered parameter
         */
        void setHovered(const bool isHovered);

      private:
        bool _isHovered;
        bool _isClicked;
    };
} // namespace ecs

#endif /* !CLICKABLE_HPP_ */
