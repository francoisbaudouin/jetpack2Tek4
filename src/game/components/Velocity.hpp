/*
** EPITECH PROJECT, 2022
** boostrapR-type
** File description:
** Velocity
*/

#pragma once
#include "AComponent.hpp"

class Velocity : public AComponent {
  public:
    Velocity();
    Velocity(float velocity);
    ~Velocity();
  protected:
    float _velocity;
};

