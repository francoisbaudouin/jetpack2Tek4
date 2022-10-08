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
#include "../ecs/enums/Event.hpp"
#include "data.hpp"

using namespace ecs;

Client::Client(std::unordered_map<size_t, std::shared_ptr<ecs::Entity>> entityMap)
    : _window(sf::VideoMode(800, 600), "Client window"), _displaySystem(entityMap),
    _moveSystem(entityMap), _inputSystem(entityMap)
{
}

Client::~Client() {}

// member function

void Client::run()
{
    while (_window.isOpen()) {
        auto test = _inputSystem.getInput(_window);
        if (test.keyboardKey == Device::KeyBoardKey::A && test.eventType == EventType::PRESSED)
            _window.close();
        _window.clear();
        _displaySystem.run(_window);
        _moveSystem.run();
        _window.display();
    }
}
