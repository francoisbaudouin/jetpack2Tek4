/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** HitBox
*/

#include "HitBox.hpp"

using namespace ecs;

HitBox::HitBox(const size_t entityId, const float sizeX, const float sizeY)
    : AComponent(entityId), _sizeX(sizeX), _sizeY(sizeY)
{
}

HitBox::~HitBox() {}

void HitBox::setHitBox(const float sizeX, const float sizeY)
{
    _sizeX = sizeX;
    _sizeY = sizeY;
}

void HitBox::setX(const float sizeX) { _sizeX = sizeX; }

void HitBox::setY(const float sizeY) { _sizeY = sizeY; }

float HitBox::getX() const { return (_sizeX); }

float HitBox::getY() const { return (_sizeY); }
