/*
** EPITECH PROJECT, 2022
** boostrapR-type
** File description:
** Drawable
*/

#pragma once
#include "AComponent.hpp"

class Drawable : public AComponent {
  public:
    Drawable();
    ~Drawable();
    bool _isDrawable;
};
