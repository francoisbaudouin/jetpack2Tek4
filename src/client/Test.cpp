/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Test
*/

#include "Test.hpp"

Test::Test()
{
    _value = 5;
    _name = "Thomas";
    _tab.push_back("salut");
    _tab.push_back("Thomas");
}

int Test::getValue() const { return this->_value; }

std::string Test::getName() const { return this->_name; }

Test::~Test() {}