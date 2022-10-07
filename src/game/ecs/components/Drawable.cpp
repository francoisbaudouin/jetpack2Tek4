/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Drawable
*/

#include "Drawable.hpp"
using namespace ecs;

Drawable::Drawable() : AComponent(0)
{
}

Drawable::Drawable(sf::Texture &texture) : AComponent(0)
{
  shipTexture.loadFromFile("src/game/assets/vesso.png");
  _sprite.setTexture(shipTexture);
}

sf::Sprite Drawable::getSprite() const
{
  return _sprite;
}

void Drawable::setSprite(sf::Sprite sprite)
{
  _sprite = sprite;
}

Drawable::~Drawable()
{
}

