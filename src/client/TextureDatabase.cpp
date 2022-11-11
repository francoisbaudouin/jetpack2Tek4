/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** TextureDatabase
*/

#include <filesystem>
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>

#include "TextureDatabase.hpp"
#include "ecs/exceptions/Exception.hpp"

using namespace rtype;

std::string fileTraduction(std::string &fileName)
{
    std::filesystem::path path(fileName);
    return path.generic_string().c_str();
}

TextureDatabase::TextureDatabase() {}

void TextureDatabase::onCall(const std::string &sceneName)
{
    boost::property_tree::ptree jsonFile;
    std::string scenePathString = "src/client/configs/" + sceneName + "/TextureConfigs/TextureConfiguration.json";
    std::string scenePath = fileTraduction(scenePathString);
    boost::property_tree::read_json(scenePath, jsonFile);

    for (auto line : jsonFile) {
        sf::Texture tmpTexture;
        if (tmpTexture.loadFromFile(fileTraduction(line.second.data())) != true) {
            throw ecs::TextureNotLoadedSuccessfully(fileTraduction(line.second.data()));
        } else
            _textureMap[line.first].loadFromFile(fileTraduction(line.second.data()));
    }
}

sf::Texture &TextureDatabase::getTexture(const std::string type)
{
    if (_textureMap.contains(type) == false)
        throw ecs::TextureNotInDatabase(type);
    return _textureMap[type];
}

void TextureDatabase::replaceTexturePath(const std::string type, sf::Texture &newTexturePath)
{
    _textureMap[type] = newTexturePath;
}

TextureDatabase::~TextureDatabase() {}
