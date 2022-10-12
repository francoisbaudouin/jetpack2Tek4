/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Client
*/

#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#include <SFML/Graphics.hpp>
#include "../ecs/systems/Controll.hpp"
#include "../ecs/systems/Display.hpp"
#include "../ecs/systems/Input.hpp"
#include "../ecs/systems/Move.hpp"

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
    ecs::Move _moveSystem;
    ecs::Input _inputSystem;
    ecs::Controll _controllSystem;
};

#endif /* !CLIENT_HPP_ */
