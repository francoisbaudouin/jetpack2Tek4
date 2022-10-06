/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Drawable
*/

#ifndef DRAWABLE_HPP_
#define DRAWABLE_HPP_

#include "AComponent.hpp"

namespace ecs
{
    class Drawable : public AComponent {
      public:
        Drawable();
        ~Drawable();
        bool _isDrawable;
    };
} // namespace ecs

#endif /* !DRAWABLE_HPP_ */
