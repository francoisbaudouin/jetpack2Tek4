/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** DrawableClientSide
*/

#include "DrawableClientSide.hpp"

using namespace ecs;

DrawableClientSide::DrawableClientSide(const size_t entityId, const sf::Texture &texture, const float scale)
    : AComponent(entityId), _scale(scale)
{
    _sprite.setTexture(texture);
}

sf::Sprite &DrawableClientSide::getSprite() { return _sprite; }

void DrawableClientSide::setSprite(const sf::Sprite &sprite) { _sprite = sprite; }

void DrawableClientSide::setScale(const float scale) { this->_scale = scale; }

float DrawableClientSide::getScale() const { return this->_scale; }

DrawableClientSide::~DrawableClientSide() {}
