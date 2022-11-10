/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Clickable
*/

#include "Clickable.hpp"

using namespace ecs;

Clickable::Clickable(const size_t entityId) : AComponent(entityId), _isHovered(false), _isClicked(false) {}

Clickable::~Clickable() {}

bool Clickable::isClicked() const { return _isClicked; }

bool Clickable::isHovered() const { return _isHovered; }

void Clickable::setClicked(const bool isClicked) { _isClicked = isClicked; }

void Clickable::setHovered(const bool isHovered) { _isHovered = isHovered; }
