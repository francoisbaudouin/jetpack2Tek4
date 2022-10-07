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
        AComponent(const size_t entityId);
        ~AComponent();

        size_t getEntityId() const override;
        void setEntityId(const size_t entityId) override;

      protected:
        size_t _entityId;
        
    };
} // namespace ecs

#endif /* !ACOMPONENT_HPP_ */
