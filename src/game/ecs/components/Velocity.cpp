/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Velocity
*/

#include "Velocity.hpp"

using namespace ecs;

Velocity::Velocity(const size_t entityId, const float velocityX, const float velocityY) : AComponent(entityId), _velocityX(velocityX), _velocityY(velocityY)
{
}

Velocity::~Velocity() {}

void Velocity::setVelocity(const float velocityX, const float velocityY)
{
    _velocityX = velocityX;
    _velocityY = velocityY;
}

void Velocity::setX(const float velocityX) { _velocityX = velocityX; }

void Velocity::setY(const float velocityY) { _velocityY = velocityY; }

float Velocity::getX() const { return (_velocityX); }

float Velocity::getY() const { return (_velocityY); }
