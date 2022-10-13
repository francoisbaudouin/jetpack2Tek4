/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Drawable
*/

#include "Drawable.hpp"

using namespace ecs;

Drawable::Drawable(const size_t entityId, const sf::Texture &texture) : AComponent(entityId)
{
    _sprite.setTexture(texture);
}

sf::Sprite &Drawable::getSprite() { return _sprite; }

void Drawable::setSprite(const sf::Sprite &sprite) { _sprite = sprite; }

Drawable::~Drawable() {}
