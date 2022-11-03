/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Loadconfig
*/

#ifndef LOADCONFIG_HPP_
#define LOADCONFIG_HPP_

#include <functional>
#include <map>
#include <string>
#include <unordered_map>

namespace configuration
{
    class Loadconfig {
      public:
        Loadconfig();
        ~Loadconfig();
        void run();

      protected:
      private:
        /**
         * @brief Set the Server Data object
         *
         * @param it
         * @return true
         * @return false
         */
        bool setServerData(std::map<std::string, std::string>::iterator it);

        /**
         * @brief Funct wich return true or false if configuration file
         * is found annd can be read
         *
         * @return true loading file sucess OK
         * @return false loading file fail KO
         */
        bool load_file();

        /**
         * @brief
         *
         * @param configFile
         */
        void load_data(std::fstream configFile);

        void setServerIp(std::string);
        std::string _ip;
        std::string _name;
        bool _debugger;
        bool _eula = false;
        size_t _port;
        size_t _gravity;
        std::string _custom_map;
        size_t maxConnection;
        std::map<std::string, std::string> _configurationServer{
            {"name", ""}, {"port", ""}, {"ip", ""}, {"debugger", ""}, {"EULA", ""}, {"max_player_connection", ""}};
        std::map<std::string, std::string> _configurationGame{{"gravity", ""}, {"velocity", ""}, {"custom_map", ""}};
        std::unordered_map<std::string, std::function<std::string>> _functPtr{
            {"ip", [this](std::string s) { _ip = s; }},
            {"name", [this](std::string name) { _name = name; }}};
    };
} // namespace configuration

#endif /* !LOADCONFIG_HPP_*/