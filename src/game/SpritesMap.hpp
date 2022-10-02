/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** SpritesMap
*/

#pragma once
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include <string>
#include "data.hpp"

class SpritesMap {
  public:
    SpritesMap();
    ~SpritesMap();

    //member function
    void update(t_data);
    void update(const std::vector<t_data>);
    void displaySprites(sf::RenderWindow &);
  protected:
  private:
    sf::Texture _playerTexture;
    sf::Texture _ennemyTexture;
    std::unordered_map<std::string, sf::Texture> _textureDatabase;
    std::unordered_map<size_t, sf::Sprite> _spritesMap;
};
