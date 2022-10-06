/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** EntityMap
*/

#pragma once
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include <string>
#include "data.hpp"
#include "Entity.hpp"

class EntityMap {
  public:
    EntityMap();
    ~EntityMap();

    //member function


  protected:
  private:
    std::unordered_map<size_t, Entity> _entityMap;
};
