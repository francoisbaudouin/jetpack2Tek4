/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Controllable
*/

#ifndef CONTROLLABLE_HPP_
#define CONTROLLABLE_HPP_

#include "AComponent.hpp"

class Controllable : public AComponent{
  public:
    Controllable();
    ~Controllable();
    bool _isControllable;
  protected:  
  private:
};

#endif /* !CONTROLLABLE_HPP_ */
