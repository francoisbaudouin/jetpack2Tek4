/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Registery
*/

#ifndef REGISTERY_HPP_
#define REGISTERY_HPP_

#include <any>
#include <iostream>
#include <typeindex>
#include <typeinfo>
#include "SparseArray.hpp"
#include <unordered_map>

class Registery {
  public:
    Registery();
    ~Registery();

    template <class Component> SparseArray<Component> &register_component();

    template <class Component> SparseArray<Component> &get_components();

    template <class Component> SparseArray<Component> const &get_components() const;

  private:
    std::unordered_map<std::type_index, std::any> _map;
};

#endif /*REGISTERY_HPP_*/