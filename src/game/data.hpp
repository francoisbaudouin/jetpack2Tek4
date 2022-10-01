/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** data
*/

#pragma once
#include <array>
#include <string>

struct data {
  size_t id;
  std::array<float, 2> pos;
  std::array<float, 2> size;
  std::string type;
};