/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Loadconfig
*/

#include <fstream>
#include "Loadconfig.hpp"
namespace initialization
{
    Loadconfig::Loadconfig() {}

    Loadconfig::~Loadconfig() {}

    bool Loadconfig::load_file()
    {
        std::ofstream configFile;

        configFile.open("../config.ini");
        return (true);
    }
} // namespace initialization