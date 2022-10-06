/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Position
*/

#ifndef POSITION_HPP_
#define POSITION_HPP_

#include "AComponent.hpp"

class Position : public AComponent {
  public:
    Position();
    Position(float x, float y);
    ~Position();

  //getters 
  float getX() const;
  float getY() const;

  //setters
  void setX(float x);
  void setY(float y);
  //member function

  private:
    float _x;
    float _y;
};

#endif /* !POSITION_HPP_ */
