/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Client
*/

#pragma once
#include <SFML/Graphics.hpp>
#include "EntityMap.hpp"

class Client {
  public:
    Client();
    ~Client();

    //member function
    void run();

  protected:
  private:
    sf::RenderWindow _window;
    EntityMap _spritesMap;
};
