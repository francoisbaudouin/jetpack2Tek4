/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** AComponent
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_

#include "IComponent.hpp"

class AComponent : public IComponent {
  public:
    AComponent();
    ~AComponent();

    // interface function
    std::string getName() const;

    // setters
    void setName(std::string);
    bool _isEnabled;
    std::string _name;

  protected:
  private:
};

#endif /* !ACOMPONENT_HPP_ */
