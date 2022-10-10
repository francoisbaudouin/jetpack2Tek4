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
#include "../ecs/enums/event.hpp"
#include "data.hpp"

using namespace ecs;

Client::Client(std::unordered_map<size_t, std::shared_ptr<ecs::Entity>> entityMap)
    : _window(sf::VideoMode(800, 600), "Client window"), _displaySystem(entityMap),
    _moveSystem(entityMap), _inputSystem(entityMap), _controllSystem(entityMap)
{
}

Client::~Client() {}

// member function

void Client::run()
{
    while (_window.isOpen()) {
        sf::Event event;
        _window.clear();
        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                _window.close();
            _controllSystem.run(_inputSystem.getInput(event));
        }
        _moveSystem.run();
        _displaySystem.run(_window);
        _window.display();
    }
}
