/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Drawable
*/

#include "Drawable.hpp"

using namespace ecs;

Drawable::Drawable(const size_t entityId) : AComponent(entityId), _textureType("Default") {}

Drawable::Drawable(const size_t entityId, const std::string &textureType)
    : AComponent(entityId), _textureType(textureType)
{
}

std::string Drawable::getTextureType() const { return _textureType; }

void Drawable::setTextureType(const std::string &newTextureType) { _textureType = newTextureType; }

Drawable::~Drawable() {}
