/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** TextureDatabase
*/

#ifndef TEXTUREDATABASE_HPP_
#define TEXTUREDATABASE_HPP_

#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>

namespace rtype
{
    class TextureDatabase {
      public:
        TextureDatabase();
        ~TextureDatabase();

        void onCall(const std::string &sceneName);
        sf::Texture &getTexture(const std::string type);
        void replaceTexturePath(const std::string type, sf::Texture &newTexturePath);

      protected:
      private:
        std::unordered_map<std::string, sf::Texture> _textureMap;
    };
} // namespace rtype

#endif /* !TEXTUREDATABASE_HPP_ */
