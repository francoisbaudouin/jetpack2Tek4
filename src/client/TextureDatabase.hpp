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

namespace rtype
{
    class TextureDatabase {
      public:
        TextureDatabase();
        ~TextureDatabase();

        void onCall(const size_t sceneId);
        void replaceTexturePath(const std::string type, const std::string newTexturePath);

      protected:
      private:
        std::unordered_map<std::string, std::string> _textureMap;
        std::vector<std::string> _configFilePath;
    };
} // namespace rtype

#endif /* !TEXTUREDATABASE_HPP_ */
