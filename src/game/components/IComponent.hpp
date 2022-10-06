/*
** EPITECH PROJECT, 2022
** boostrap
** File description:
** IComponent
*/

#pragma once
#include <string>

class IComponent {
  public:
    virtual ~IComponent() = default;
    virtual std::string getName() const = 0;

  private:
};
