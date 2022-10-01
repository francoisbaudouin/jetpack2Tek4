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
  sf::Sprite playerSprite;
  sf::Sprite ennemySprite;

  _ennemyTexture.loadFromFile("src/game/assets/ohnonmonstermunch.png");
  _playerTexture.loadFromFile("src/game/assets/vesso.png");

  playerSprite.setTexture(_playerTexture);
  ennemySprite.setTexture(_ennemyTexture);
  ennemySprite.setPosition(sf::Vector2f{100, 0});


  _spritesMap = {{0, playerSprite}, {1, ennemySprite}};
}

SpritesMap::~SpritesMap()
{
}

//member function

void SpritesMap::displaySprites(sf::RenderWindow &window)
{
    for(std::pair<size_t, sf::Sprite> n : _spritesMap) {
      window.draw(n.second);
    }
}
