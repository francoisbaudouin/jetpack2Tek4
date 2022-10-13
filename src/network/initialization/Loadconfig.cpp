/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Loadconfig
*/

#include <fstream>
#include "Loadconfig.hpp"
#include <string>

namespace initialization
{
    Loadconfig::Loadconfig() {}

    Loadconfig::~Loadconfig() {}

    bool Loadconfig::load_file()
    {
        std::ofstream configFile;

        if (configFile.is_open()) {

        } else {
            
        }
        configFile.close();
        return (true);
    }
} // namespace initialization