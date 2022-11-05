/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** DrawableClientSide
*/

#include "DrawableClientSide.hpp"

using namespace ecs;

DrawableClientSide::DrawableClientSide(const size_t entityId, const sf::Texture &texture) : AComponent(entityId)
{
    _sprite.setTexture(texture);
}

sf::Sprite &DrawableClientSide::getSprite() { return _sprite; }

void DrawableClientSide::setSprite(const sf::Sprite &sprite) { _sprite = sprite; }

DrawableClientSide::~DrawableClientSide() {}
