/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Client
*/

#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#include <SFML/Graphics.hpp>
#include "../ecs/systems/Display.hpp"
#include "SpritesMap.hpp"

class Client {
  public:
    Client();
    Client(std::unordered_map<size_t, std::shared_ptr<ecs::Entity>> entityMap);

    ~Client();

    // member function
    void run();

  protected:
  private:
    sf::RenderWindow _window;
    SpritesMap _spritesMap;
    ecs::Display _displaySystem;
};

#endif /* !CLIENT_HPP_ */
