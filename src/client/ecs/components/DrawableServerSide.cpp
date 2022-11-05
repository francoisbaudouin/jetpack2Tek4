/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Drawable
*/

#include "DrawableServerSide.hpp"

using namespace ecs;

DrawableServerSide::DrawableServerSide(const size_t entityId) : AComponent(entityId), _textureType("Default") {}

DrawableServerSide::DrawableServerSide(const size_t entityId, const std::string &textureType)
    : AComponent(entityId), _textureType(textureType)
{
}

std::string DrawableServerSide::getTextureType() const { return _textureType; }

void DrawableServerSide::setTextureType(const std::string &newTextureType) { _textureType = newTextureType; }

DrawableServerSide::~DrawableServerSide() {}
