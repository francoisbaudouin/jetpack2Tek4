/*
** EPITECH PROJECT, 2022
** boostrapR-type
** File description:
** AComponent
*/


#include "AComponent.hpp"

AComponent::AComponent() : _name("Undefined component")
{
}

AComponent::~AComponent()
{
}

std::string AComponent::getName() const
{
  return _name;
}

void AComponent::setName(std::string name)
{
  _name = name;
}