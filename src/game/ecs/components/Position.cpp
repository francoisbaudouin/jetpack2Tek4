/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Position
*/

#include "Position.hpp"

using namespace ecs;

Position::Position(const size_t entityId, const float positionX, const float positionY) : AComponent(entityId), _positionX(positionX), _positionY(positionY)
{
}

Position::~Position() {}

void Position::setPosition(const float positionX, const float positionY)
{
    _positionX = positionX;
    _positionY = positionY;
}

void Position::setX(const float positionX) { _positionX = positionX; }

void Position::setY(const float positionY) { _positionY = positionY; }

float Position::getX() const { return (_positionX); }

float Position::getY() const { return (_positionY); }
