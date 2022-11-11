/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Test
*/
#ifndef TEST_HPP_
#define TEST_HPP_

#include <iostream>
#include <vector>

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
    int getValue() const;
    std::string getName() const;
    ~Test();

  protected:
  private:
    int _value;
    std::string _name;
    std::vector<std::string> _tab;
};

#endif /* !TEST_HPP_ */