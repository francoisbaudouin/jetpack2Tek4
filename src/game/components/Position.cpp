/*
** EPITECH PROJECT, 2022
** boostrap
** File description:
** Position
*/

#include "Position.hpp"

Position::Position() :_x(0), _y(0)
{
  _name = "Position";
}

Position::Position(int x, int y) :_x(x), _y(y)
{
  _name = "Position";
}

//getters

int Position::getX() const
{
  return _x;
}

int Position::getY() const
{
  return _y;
}

//setters

void Position::setX(int x)
{
  _x  = x;
}

void Position::setY(int y)
{
  _y = y;
}

//member function

Position::~Position()
{
}
