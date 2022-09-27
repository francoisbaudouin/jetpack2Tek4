/*
** EPITECH PROJECT, 2022
** boostrap
** File description:
** PositionComp
*/

#pragma once
#include "AComponent.hpp"

class Position : public AComponent {
  public:
    Position();
    Position(int x, int y);
    ~Position();

  //getters 
  int getX() const;
  int getY() const;

  //setters
  void setX(int x);
  void setY(int y);
  //member function

  private:
    int _x;
    int _y;
};
