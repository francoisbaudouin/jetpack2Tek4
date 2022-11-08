/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Test
*/
#ifndef TEST_HPP_
#define TEST_HPP_

#include <iostream>

class Test {
  public:
    Test();
    friend std::ostream &operator<<(std::ostream &out, Test &test)
    {
        out << test._value << " " << test._name;

        return out;
    }
    friend std::istream &operator>>(std::istream &in, Test &test)
    {
        in >> test._value;
        in >> test._name;

        return in;
    }
    ~Test();

  protected:
  private:
    int _value;
    std::string _name;
};

#endif /* !TEST_HPP_ */
