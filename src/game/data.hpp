/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** data
*/

#ifndef DATA_HPP_
#define DATA_HPP_

#include <array>
#include <string>

struct t_data {
  size_t id;
  std::array<float, 2> pos;
  std::array<float, 2> size;
  std::string type;
};

#endif /* !DATA_HPP_ */
