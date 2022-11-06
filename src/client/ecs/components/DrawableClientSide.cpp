/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** DrawableClientSide
*/

#include "DrawableClientSide.hpp"

using namespace ecs;

DrawableClientSide::DrawableClientSide(const size_t entityId, const sf::Texture &texture, const float scale)
    : AComponent(entityId)
{
    sf::Vector2f scaleVector(scale, scale);
    _scale = scaleVector;

    _sprite.setTexture(texture);
    _sprite.setScale(_scale);
}

sf::Sprite &DrawableClientSide::getSprite() { return _sprite; }

void DrawableClientSide::setSprite(const sf::Sprite &sprite) { _sprite = sprite; }

void DrawableClientSide::setScale(const float scale)
{
    sf::Vector2f scaleVector(scale, scale);

    this->_scale = scaleVector;
}

sf::Vector2f DrawableClientSide::getScale() const { return this->_scale; }

DrawableClientSide::~DrawableClientSide() {}
