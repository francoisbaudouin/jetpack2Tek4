/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Client
*/

#include "Client.hpp"
#include "data.hpp"
#include "Entity.hpp"
#include "systems/Display.hpp"
#include "components/Drawable.hpp"
#include "components/Position.hpp"
#include <iostream>

Client::Client() : _window(sf::VideoMode(800, 600), "Client window")
{

}

Client::~Client()
{
}

//member function

void update(Entity &ent)
{
  Position &pos = ent.getComponent<Position>();

  pos.setX(pos.getX() + 0.1);
}

void Client::run()
{
  Display dis;
  Entity ent(0);
    ent.addComponent<Position>();
    ent.addComponent<Drawable>();

  while (_window.isOpen()) {
    sf::Event event;
    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            _window.close();
    }
    update(ent);
    dis.addData(ent);
    _spritesMap.update(dis.getData());
    _spritesMap.displaySprites(_window);
    _window.display();
    _window.clear();
    dis.clearData();
  }
}

