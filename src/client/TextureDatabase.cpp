/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** TextureDatabase
*/

#include "TextureDatabase.hpp"
#include <iostream>
#include <vector>

using namespace rtype;

TextureDatabase::TextureDatabase()
{
  _configFilePath.push_back("src/client/configs/game/TexturesConfigs/TextureConfiguration.json");
  _configFilePath.push_back("src/client/configs/menu/TextureConfigs/TextureConfiguration.json");
}

void TextureDatabase::onCall(const size_t sceneId)
{
  boost::property_tree::ptree jsonFile;
  boost::property_tree::read_json(_configFilePath[sceneId], jsonFile);

  for (auto test : jsonFile) {
    _textureMap[test.first] = test.second.data();
  }
}

void TextureDatabase::onCall(const size_t sceneId)
{
  boost::property_tree::ptree jsonFile;
  boost::property_tree::read_json(_configFilePath[sceneId], jsonFile);

  for (auto test : jsonFile) {
    _textureMap[test.first] = test.second.data();
  }
}

void TextureDatabase::replaceTexturePath(const std::string type, const std::string newTexturePath)
{
  _textureMap[type] = newTexturePath;
}

TextureDatabase::~TextureDatabase()
{
}

