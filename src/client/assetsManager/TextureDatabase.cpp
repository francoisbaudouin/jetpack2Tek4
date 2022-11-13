/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** TextureDatabase
*/

#include "fileOpener.hpp"

#include "../ecs/exceptions/Exception.hpp"
#include "TextureDatabase.hpp"

using namespace rtype;

TextureDatabase::TextureDatabase() {}

void TextureDatabase::onCall(const std::string &sceneName)
{
    std::string path = "assets/configFiles/" + sceneName + "/Textures.json";
    boost::property_tree::ptree jsonFile = openJsonFile(path);

    for (auto line : jsonFile) {
        sf::Texture tmpTexture;
        if (tmpTexture.loadFromFile(fileTraduction(line.second.data())) != true)
            throw ecs::TextureNotLoadedSuccessfully(fileTraduction(line.second.data()));
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

size_t TextureDatabase::getSizeX(const std::string type)
{
    if (_textureMap.contains(type) == false)
        throw ecs::TextureNotInDatabase(type);
    return _textureMap[type].getSize().x;
}
size_t TextureDatabase::getSizeY(const std::string type)
{
    if (_textureMap.contains(type) == false)
        throw ecs::TextureNotInDatabase(type);
    return _textureMap[type].getSize().y;
}
