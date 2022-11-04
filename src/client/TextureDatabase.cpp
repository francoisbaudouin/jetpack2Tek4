/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** TextureDatabase
*/

#define BOOST_BIND_NO_PLACEHOLDERS

#include <boost/bind.hpp>
#include <filesystem>
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>

#include "TextureDatabase.hpp"
#include "ecs/exceptions/Exception.hpp"

using namespace rtype;
using namespace boost::placeholders;

std::string fileTraduction(std::string &fileName)
{
    std::filesystem::path path(fileName);
    return path.generic_string().c_str();
}

TextureDatabase::TextureDatabase()
{
    _configFilePath.push_back("src/client/configs/game/TexturesConfigs/TextureConfiguration.json");
    _configFilePath.push_back("src/client/configs/menu/TextureConfigs/TextureConfiguration.json");
}

void TextureDatabase::onCall(const size_t sceneId)
{
    boost::property_tree::ptree jsonFile;
    boost::property_tree::read_json(_configFilePath[sceneId], jsonFile);

    for (auto line : jsonFile) {
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
