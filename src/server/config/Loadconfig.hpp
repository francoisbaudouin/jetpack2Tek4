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
#include <regex>
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
         * @param line Contains line data from config.ini
         * @param regex use following regular expression patern ([a-z]*)=([a-z]*) to approve line format
         * @return true In case if data is allowed
         * @return false In case if data dosn't allowed
         * @throw Data wich does't provice here
         */
        bool setServerData(std::string line, std::regex regex, std::smatch match);

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

        std::string _ip;
        std::string _name;
        std::string _debugger;
        bool _eula = false;
        size_t _port;
        size_t _gravity;
        size_t _velocity;
        std::string _custom_map;
        size_t _maxConnection;
        std::unordered_map<std::string, std::function<void(std::string)>> _functPtr{
            {"ip", [this](std::string ip) { _ip = ip; }}, {"name", [this](std::string name) { _name = name; }},
            {"port",
                [this](std::string port) {
                    std::stringstream sstream(port);
                    sstream >> _port;
                }},
            {"debugger", [this](std::string debugger) { _debugger = debugger; }},
            {"EULA",
                [this](std::string eula) {
                    if (eula.compare("true") == 0)
                        _eula = true;
                }},
            {"max_player_connection",
                [this](std::string playerMax) {
                    std::stringstream sstream(playerMax);
                    sstream >> _maxConnection;
                }},
            {"gravity",
                [this](std::string gravity) {
                    std::stringstream sstream(gravity);
                    sstream >> _gravity;
                }},
            {"velocity",
                [this](std::string velocity) {
                    std::stringstream sstream(velocity);
                    sstream >> _velocity;
                }},
            {"custom_map", [this](std::string customMap) { customMap = _custom_map; }}};
    };
} // namespace configuration

#endif /* !LOADCONFIG_HPP_*/