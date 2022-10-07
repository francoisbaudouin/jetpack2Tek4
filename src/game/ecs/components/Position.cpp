/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Position
*/

#include "Position.hpp"

using namespace ecs;

Position::Position(const size_t entId, const float posX, const float posY) : AComponent(entId), _posX(posX), _posY(posY)
{
}

Position::~Position() {}

void Position::setPos(const float posX, const float posY)
{
    _posX = posX;
    _posY = posY;
}

void Position::setX(const float posX) { _posX = posX; }

void Position::setY(const float posY) { _posY = posY; }

float Position::getX() const { return (_posX); }

float Position::getY() const { return (_posY); }
