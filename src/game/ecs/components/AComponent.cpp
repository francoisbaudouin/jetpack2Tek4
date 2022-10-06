/*
** EPITECH PROJECT, 2022
** boostrapR-type
** File description:
** AComponent
*/

#include "AComponent.hpp"

using namespace ecs;

AComponent::AComponent(const size_t entId) { _entId = entId; }

AComponent::~AComponent() {}

size_t AComponent::getEntId() const { return (_entId); }

void AComponent::setEntId(const size_t entId) { _entId = entId; }
