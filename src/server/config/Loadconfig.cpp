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

#define CONFIG_PATH "src/network/config.ini"

namespace configuration
{
    Loadconfig::Loadconfig() {}

    Loadconfig::~Loadconfig() {}

    bool Loadconfig::load_file()
    {
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

    bool Loadconfig::setServerData(std::map<std::string, std::string>::iterator it)
    {
        std::map<std::string, std::string>::iterator tmp;
        while (it->first.compare("") != 0 && it != _configurationServer.end()) {
            tmp = it;
            while(tmp != _configurationServer.end()) {
                
            }
            
        }
        return (true);
    }

    void Loadconfig::load_data(std::fstream configFile)
    {
        std::string line;

        while (std::getline(configFile, line)) {
            for (std::map<std::string, std::string>::iterator it = _configurationServer.begin();
                 it != _configurationServer.end(); it++) {
                    if (line.compare("[server]"))
                        setServerData(it);
                 }
        }
    }
} // namespace configuration