/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Selectable
*/

#ifndef SELECTABLE_HPP_
#define SELECTABLE_HPP_

#include "AComponent.hpp"

namespace ecs
{
    class Selectable : public AComponent {
      public:
      /**
       * @brief make an entity selectable when clicked
       * 
       * @param entityId id of the related entity
       */
        Selectable(const size_t entityId);
        ~Selectable();
        /**
         * @brief set the selected property to the bool given in parameter
         *
         * @param isSelected selected will take this value
         */
        void setSelected(bool isSelected);
        /**
         * @brief Get the Selected property
         *
         * @return true if selected
         * @return false if not selecred
         */
        bool isSelected() const;

      protected:
      private:
        bool _isSelected;
    };
} // namespace ecs

#endif /* !SELECTABLE_HPP_ */
