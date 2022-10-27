/*
** EPITECH PROJECT, 2022
** boostrapR-type
** File description:
** AComponent
*/

#include "AComponent.hpp"

using namespace ecs;

AComponent::AComponent(const size_t entityId) : _entityId(entityId) {}

AComponent::~AComponent() {}

size_t AComponent::getEntityId() const { return (_entityId); }

void AComponent::setEntityId(const size_t entId) { _entityId = entId; }
