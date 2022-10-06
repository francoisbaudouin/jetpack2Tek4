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
#include "../data.hpp"

namespace ecs
{
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
} // namespace ecs

#endif /* !DISPLAY_HPP_ */
