/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Input
*/

#include "Input.hpp"
#include <iostream>

using namespace ecs;

Input::Input(std::unordered_map<size_t, std::shared_ptr<ecs::Entity>> &entityMap) : ASystem(entityMap) {}

Input::~Input() {}

RTypeEvent Input::getInput(sf::RenderWindow &window)
{
    sf::Event event;

    _event.keyboardKey = Device::KeyBoardKey::UNKNOWN_KEYBOARD_KEY;
    _event.mouseKey = Device::MouseKey::UNKNOWN_MOUSE_KEY;
    _event.eventType = EventType::UNKNOWN_TYPE;

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A) {
          _event.keyboardKey = Device::KeyBoardKey::A;
          _event.eventType  = EventType::PRESSED;
        }
      return (_event);
    }
}