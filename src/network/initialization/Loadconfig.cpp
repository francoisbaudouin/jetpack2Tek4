/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Loadconfig
*/

#include <fstream>
#include <string>
#include "../exception/Exception.hpp"
#include "Loadconfig.hpp"

namespace initialization
{
    Loadconfig::Loadconfig() {}

    Loadconfig::~Loadconfig() {}

    bool Loadconfig::load_file()
    {
        std::ofstream configFile("../config.atom");

        if (configFile.is_open()) {
        } else {
            throw rtype::InvalideUnknownFile("Can't open config file:");
        }
        configFile.close();
        return (true);
    }
} // namespace initialization
