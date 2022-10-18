/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Loadconfig
*/

#ifndef LOADCONFIG_HPP_
#define LOADCONFIG_HPP_

#include <string>
#include <map>

namespace configuration
{
    class Loadconfig {
      public:
        Loadconfig();
        ~Loadconfig();
        void run();

      protected:
      private:
        bool load_file();
        void load_data(std::fstream configFile);
        std::string _ip;
        std::string _name;
        bool _debugger;
        bool _eula = false;
        size_t _port;
        size_t _gravity;
        std::string _custom_map;
        size_t maxConnection;
        std::map<std::string, std::string> _configurationServer{{"name",""}, {"port",""}, {"ip",""}, {"debugger",""}, {"EULA",""}, {"max_player_connection",""}};
        std::map<std::string, std::string> _configurationGame{{"gravity",""}, {"velocity",""}, {"custom_map",""}};
    };
} // namespace configuration

#endif /* !LOADCONFIG_HPP_*/