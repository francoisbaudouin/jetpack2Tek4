/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Registery
*/

#include "Registery.hpp"

Registery::Registery() : _map() {}

Registery::~Registery() {}

template <class Component>
SparseArray<Component> &Registery::register_component()
{
  if (_map.find(std::type_index(typeid(Component))) != _map.end())
    _map.insert({std::type_index(typeid(Component)), SparseArray<Component>::SparseArray()});
  return (_map.at(std::type_index(typeid(Component))));
}

template <class Component>
SparseArray<Component> &Registery::get_components()
{
  return (std::any_cast<SparseArray<Component>>(_map.at(std::type_index(typeid(Component)))));
}

template <class Component>
SparseArray<Component> const &Registery::get_components() const
{
  return (std::any_cast<SparseArray<Component>>(_map.at(std::type_index(typeid(Component)))));
}
