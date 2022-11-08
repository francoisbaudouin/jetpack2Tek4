/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Loadconfig
*/

#include <filesystem>
#include <fstream>
#include <string>
#include "../exception/Exception.hpp"
#include "Loadconfig.hpp"

#define CONFIG_PATH "src/network/config.ini"

namespace configuration
{
    Loadconfig::Loadconfig() {}

    Loadconfig::~Loadconfig() {}

    bool Loadconfig::setServerData(std::string line, std::regex regex)
    {
        auto it = _functPtr.find("line");

        if (it == it->end())
        return (true);
    }

    void Loadconfig::load_data(std::fstream configFile)
    {
        std::string line;
        std::regex const regex("([a-z]*)=([a-z]*)");

        while (std::getline(configFile, line)) {
            if (line.compare("[server]"))
                setServerData(line, regex);
        }
    }

    bool Loadconfig::load_file()
    {
        std::filesystem::path fileName = "src/network/config.ini";

        std::ifstream configFile;
        configFile.open(CONFIG_PATH, std::fstream::in);
        if (configFile.is_open() == true) {
        } else {
            configFile.close();
            throw rtype::InvalideUnknownFile("Can't open config file:");
            return (false);
        }
        configFile.close();
        return (true);
    }

    void Loadconfig::run() { load_file(); }
} // namespace configuration