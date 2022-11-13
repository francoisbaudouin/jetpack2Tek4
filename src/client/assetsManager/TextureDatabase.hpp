/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** TextureDatabase
*/

#ifndef TEXTUREDATABASE_HPP_
#define TEXTUREDATABASE_HPP_

#include <SFML/Graphics.hpp>
#include <map>
#include <string>

namespace rtype
{
    class TextureDatabase {
      public:
        TextureDatabase();
        ~TextureDatabase();

        void onCall(const std::string &sceneName);
        sf::Texture &getTexture(const std::string type);
        void replaceTexturePath(const std::string type, sf::Texture &newTexturePath);
        size_t getSizeX(const std::string type);
        size_t getSizeY(const std::string type);

      protected:
      private:
        std::map<std::string, sf::Texture> _textureMap;
    };
} // namespace rtype

#endif /* !TEXTUREDATABASE_HPP_ */
