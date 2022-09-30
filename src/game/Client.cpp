/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Client
*/

#include "Client.hpp"

Client::Client() : _window(sf::VideoMode(800, 600), "Client window")
{

}

Client::~Client()
{
}

//member function

void Client::run()
{
  while (_window.isOpen()) {
    sf::Event event;
      while (_window.pollEvent(event)) {
          if (event.type == sf::Event::Closed)
              _window.close();
      }
    _window.clear();
    _window.display();
  }
}

