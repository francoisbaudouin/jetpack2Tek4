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
        AComponent(const size_t entId);
        ~AComponent();

        size_t getEntId() const;
        void setEntId(const size_t entId);

      protected:
        size_t _entId;
        
    };
} // namespace ecs

#endif /* !ACOMPONENT_HPP_ */
