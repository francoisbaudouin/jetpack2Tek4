/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** fileOpener
*/

#include <filesystem>

#include "fileOpener.hpp"

#include "../ecs/exceptions/Exception.hpp"

namespace rtype
{

    std::string fileTraduction(std::string &fileName)
    {
        std::filesystem::path path(fileName);
        return path.generic_string().c_str();
    }

    boost::property_tree::ptree openJsonFile(std::string &fileName)
    {
        boost::property_tree::ptree jsonFile;
        std::string scenePath = fileTraduction(fileName);
        try {
            boost::property_tree::read_json(scenePath, jsonFile);
        } catch (std::exception &error) {
            throw ecs::JsonFileOpenerFailed(fileName);
        }
        return (jsonFile);
    }
} // namespace rtype