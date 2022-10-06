/*
** EPITECH PROJECT, 2022
** boostrapR-type
** File description:
** AComponent
*/

#pragma once
#include "IComponent.hpp"

class AComponent : public IComponent {
  public:
    AComponent();
    ~AComponent();

    //interface function
    std::string getName() const;

    //setters
    void setName(std::string);
    bool _isEnabled;
    std::string _name;

  protected:
  private:
};
