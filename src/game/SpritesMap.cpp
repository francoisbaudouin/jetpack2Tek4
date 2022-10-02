/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** SpritesMap
*/

#include "SpritesMap.hpp"
#include <iostream>

SpritesMap::SpritesMap()
{
  sf::Texture pTexture;
  sf::Texture eTexture;

  pTexture.loadFromFile("src/game/assets/vesso.png");
  eTexture.loadFromFile("src/game/assets/ohnonmonstermunch.png");

  _textureDatabase = {{"Player", pTexture}, {"Ennemy", eTexture}};
}

SpritesMap::~SpritesMap()
{
}

//member function

void SpritesMap::update(t_data datas)
{
  if (_spritesMap.contains(datas.id)) {
    _spritesMap[datas.id].setPosition(sf::Vector2f(datas.pos[0], datas.pos[1]));
  } else {
    sf::Sprite sprite;
    sprite.setTexture(_textureDatabase[datas.type]);
    sprite.setPosition(sf::Vector2f(datas.pos[0], datas.pos[1]));
    _spritesMap.insert({datas.id, sprite});
  }
}

void SpritesMap::update(const std::vector<t_data> datasVec)
{
  if (datasVec.size() == 0)
    return;
  for (size_t i = 0; i < datasVec.size(); i++) {
    update(datasVec[i]);
  }
}

void SpritesMap::displaySprites(sf::RenderWindow &window)
{
    for(std::pair<size_t, sf::Sprite> n : _spritesMap) {
      window.draw(n.second);
    }
}
