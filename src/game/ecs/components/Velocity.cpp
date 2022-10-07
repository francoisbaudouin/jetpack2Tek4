/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Velocity
*/

#include "Velocity.hpp"

using namespace ecs;

Velocity::Velocity(const size_t entId, const float velX, const float velY) : AComponent(entId), _velX(velX), _velY(velY)
{
}

Velocity::~Velocity() {}

void Velocity::setVel(const float velX, const float velY)
{
    _velX = velX;
    _velY = velY;
}

void Velocity::setX(const float velX) { _velX = velX; }

void Velocity::setY(const float velY) { _velY = velY; }

float Velocity::getX() const { return (_velX); }

float Velocity::getY() const { return (_velY); }
