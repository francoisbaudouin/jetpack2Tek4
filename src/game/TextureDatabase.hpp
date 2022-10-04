/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** TextureDatabase
*/

#pragma once
#include <unordered_map>
#include "enum.hpp"
#include <SFML/Graphics.hpp>
/* THIS IS FOR THE FUTURE */

class TextureDatabase {
  public:
    TextureDatabase();
    ~TextureDatabase();

    //getters
    std::unordered_map<TextureType, sf::Texture> getMap() const;
    sf::Texture getTextureAt(TextureType type) const;
    TextureType getTextureType(sf::Texture texture) const;

    //setters
    void setMap(std::unordered_map<TextureType, sf::Texture> map);
    void setTextureAt(TextureType type);
    void setTypeAt(sf::Texture texture);

    //operators

    //member function
    void registerTexture(TextureType textureType, sf::Texture texture);
    void eraseTexture(TextureType);
    void eraseTexture(sf::Texture);

  protected:
  private:
    std::unordered_map<TextureType, sf::Texture> _textureMap;

};
