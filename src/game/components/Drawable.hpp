/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Drawable
*/

#ifndef DRAWABLE_HPP_
#define DRAWABLE_HPP_

#include "AComponent.hpp"

class Drawable : public AComponent {
  public:
    Drawable();
    ~Drawable();
    bool _isDrawable;
};

#endif /* !DRAWABLE_HPP_ */
