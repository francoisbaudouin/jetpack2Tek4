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
    Test(const std::string &name = "Tom", int value = 4);
    friend std::ostream &operator<<(std::ostream &out, Test &test)
    {
        out << test._value << " " << test._name << " ";

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
    std::string _name;
    int _value;
};

#endif /* !TEST_HPP_ */
