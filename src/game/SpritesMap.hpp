/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** SpritesMap
*/

#pragma once
#include <unordered_map>
#include <SFML/Graphics.hpp>

class SpritesMap {
  public:
    SpritesMap();
    ~SpritesMap();

    //member function
    void displaySprites(sf::RenderWindow &);
  protected:
  private:
    sf::Texture _playerTexture;
    sf::Texture _ennemyTexture;
    std::unordered_map<size_t, sf::Sprite> _spritesMap;
};
