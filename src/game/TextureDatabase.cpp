/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** TextureDatabase
*/


/* THIS IS FOR THE FUTURE */

#include "TextureDatabase.hpp"

TextureDatabase::TextureDatabase()
{
}

TextureDatabase::~TextureDatabase()
{
}

void TextureDatabase::registerTexture(TextureType type, sf::Texture texture)
{
  _textureMap.insert({type, texture});
}
