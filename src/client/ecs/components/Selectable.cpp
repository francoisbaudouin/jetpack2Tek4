/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Selectable
*/

#include "Selectable.hpp"

using namespace ecs;

Selectable::Selectable(const size_t entityId) : AComponent(entityId), _isSelected(false) {}

Selectable::~Selectable() {}

void Selectable::setSelected(const bool isSelected) { _isSelected = isSelected; }

bool Selectable::isSelected() const { return _isSelected; }
