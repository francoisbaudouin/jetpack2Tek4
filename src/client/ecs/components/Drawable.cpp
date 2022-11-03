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

Drawable::Drawable(const size_t entityId, const sf::Texture &texture, const float scale)
    : AComponent(entityId), _scale(scale)
{
    _sprite.setTexture(texture);
    _sprite.setScale(1 * _scale, 1 * _scale);
}

sf::Sprite &Drawable::getSprite() { return _sprite; }

void Drawable::setSprite(const sf::Sprite &sprite) { _sprite = sprite; }

float Drawable::getScale() const { return _scale; }

void Drawable::setScale(const float newScale) { _scale = newScale; }

Drawable::~Drawable() {}
