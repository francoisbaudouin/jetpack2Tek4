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

Position::Position(float x, float y) :_x(x), _y(y)
{
  _name = "Position";
}

//getters

float Position::getX() const
{
  return _x;
}

float Position::getY() const
{
  return _y;
}

//setters

void Position::setX(float x)
{
  _x  = x;
}

void Position::setY(float y)
{
  _y = y;
}

//member function

Position::~Position()
{
}
