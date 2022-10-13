/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** AComponent
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_

#include "IComponent.hpp"

namespace ecs
{
    class AComponent : public IComponent {
      public:
        /**
         * @brief Construct a new AComponent object
         *
         * @param entityId : ID of the entity using this component
         */
        AComponent(const size_t entityId);
        /**
         * @brief Destroy the AComponent object
         *
         */
        ~AComponent();

        /**
         * @brief Get ID of the entity using this component
         *
         * @return size_t : ID of the entity
         */
        size_t getEntityId() const override;
        /**
         * @brief Set ID of the entity using this component
         *
         * @param entityId : new ID for the entity
         */
        void setEntityId(const size_t entityId) override;

      protected:
        size_t _entityId;
    };
} // namespace ecs

#endif /* !ACOMPONENT_HPP_ */
