/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Client
*/

#include "Client.hpp"
#include <iostream>
#include "../ecs/components/Drawable.hpp"
#include "../ecs/entity/Entity.hpp"
#include "../ecs/systems/ASystem.hpp"
#include "../ecs/systems/Display.hpp"
#include "data.hpp"

Client::Client(std::unordered_map<size_t, std::shared_ptr<ecs::Entity>> entityMap)
    : _window(sf::VideoMode(800, 600), "Client window"), _displaySystem(entityMap)
{
}

Client::~Client() {}

// member function

void Client::run()
{
    while (_window.isOpen()) {
        sf::Event event;
        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                _window.close();
        }
        _window.clear();
        _displaySystem.run(_window);
        _window.display();
    }
}
