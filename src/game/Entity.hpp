/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Entity
*/

#pragma once
#include <string>

class Entity {
  public:
    Entity();
    ~Entity();

    size_t getId() const;

  protected:
  private:
    size_t _id;
};
