/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Display
*/

#ifndef DISPLAY_HPP_
#define DISPLAY_HPP_

#include <array>
#include <string>
#include <vector>
#include "../Entity.hpp"

struct t_data {
    size_t id;
    std::array<float, 2> pos;
    std::array<float, 2> size;
    std::string type;
};

class Display {
  public:
    Display();
    ~Display();

    void clearData();
    void addData(Entity &);
    std::vector<t_data> getData() const;

  private:
    std::vector<t_data> _data;
};

#endif /* !DISPLAY_HPP_ */
