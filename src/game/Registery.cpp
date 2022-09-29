/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Registery
*/

#include "Registery.hpp"
#include "components/Position.hpp"
#include "components/Drawable.hpp"

Registery::Registery() : _map() {}

Registery::~Registery() {}

template <class Component>
SparseArray<Component> &Registery::register_component()
{
  SparseArray<Component> sparse;

  _map.insert({std::type_index(typeid(Component)), sparse});
  std::cout << _map.size() << std::endl;
  std::cout << typeid(std::any_cast<SparseArray<Component> &>(_map.at(std::type_index(typeid(Component))))).name() << std::endl;
  return (std::any_cast<SparseArray<Component> &>(_map.at(std::type_index(typeid(Component)))));
}

template <class Component>
SparseArray<Component> &Registery::get_components()
{
  return (std::any_cast<SparseArray<Component> &>(_map.at(std::type_index(typeid(Component)))));
}

// template <class Component>
// SparseArray<Component> const &Registery::get_components() const
// {
//   return (std::any_cast<SparseArray<Component> &>(_map.at(std::type_index(typeid(Component)))));
// }

template SparseArray<Position> &Registery::register_component<Position>();
template SparseArray<Drawable> &Registery::register_component<Drawable>();

template SparseArray<Position> &Registery::get_components<Position>();
template SparseArray<Drawable> &Registery::get_components<Drawable>();

// template SparseArray<Position> const &Registery::get_components<Position>() const;
// template SparseArray<Drawable> const &Registery::get_components<Drawable>() const;
