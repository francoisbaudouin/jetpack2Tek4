/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** TextureDatabase
*/

#ifndef TEXTUREDATABASE_HPP_
#define TEXTUREDATABASE_HPP_

#include <unordered_map>
#include <string>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <SFML/Graphics.hpp>
#include <filesystem>
#include "ecs/exceptions/Exception.hpp"

namespace rtype
{
    class TextureDatabase {
      public:
        TextureDatabase();
        ~TextureDatabase();

        void onCall(const size_t sceneId);
        sf::Texture &getTexture(const std::string type);
        void replaceTexturePath(const std::string type, sf::Texture &newTexturePath);

      protected:
      private:
        std::unordered_map<std::string, sf::Texture> _textureMap;
        std::vector<std::string> _configFilePath;
    };
} // namespace rtype

#endif /* !TEXTUREDATABASE_HPP_ */
