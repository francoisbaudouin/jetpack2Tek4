/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Registery
*/

#pragma once

#include <any>
#include <typeindex>
#include <typeinfo>
#include "SparseArray.hpp"
#include <unordered_map>
#include <iostream>

class Registery {
  public:
    Registery();
    ~Registery();

    template <class Component>
    SparseArray<Component> &register_component();

    template <class Component>
    SparseArray<Component> &get_components();

    template <class Component>
    SparseArray<Component> const &get_components() const;


  private:
    std::unordered_map<std::type_index, std::any> _map;
};
