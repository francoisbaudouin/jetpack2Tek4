/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Input
*/

#include "Input.hpp"

using namespace ecs;

Input::Input(std::shared_ptr<Ecs> &manager) : ASystem(manager), _events() {}

Input::~Input() {}

void Input::bindEventType(const sf::Event &event)
{
    switch (event.type) {
        case sf::Event::KeyPressed: _event.eventType = EventType::PRESSED; break;
        case sf::Event::MouseButtonPressed: _event.eventType = PRESSED; break;
        case sf::Event::KeyReleased: _event.eventType = REALEASED; break;
        case sf::Event::MouseButtonReleased: _event.eventType = REALEASED; break;
        default: _event.eventType = UNKNOWN_TYPE;
    }
}

void Input::bindKeyboardKey(const sf::Event &event)
{
    switch (event.key.code) {
        case sf::Keyboard::Z: _event.keyboardKey = Device::KeyBoardKey::Z; break;
        case sf::Keyboard::Q: _event.keyboardKey = Device::KeyBoardKey::Q; break;
        case sf::Keyboard::S: _event.keyboardKey = Device::KeyBoardKey::S; break;
        case sf::Keyboard::D: _event.keyboardKey = Device::KeyBoardKey::D; break;
        case sf::Keyboard::Space: _event.keyboardKey = Device::KeyBoardKey::Space; break;
        default: _event.keyboardKey = Device::KeyBoardKey::UNKNOWN_KEYBOARD_KEY;
    }
}

void Input::bindMouseKey(const sf::Event &event)
{
    switch (event.key.code) {
        case sf::Mouse::Button::Left: _event.mouseKey = Device::MouseKey::LEFT; break;
        case sf::Mouse::Button::Right: _event.mouseKey = Device::MouseKey::RIGHT; break;
        default: _event.mouseKey = Device::MouseKey::UNKNOWN_MOUSE_KEY;
    }
}

void Input::updateEvents()
{
    for (auto iterator = _events.begin(); iterator < _events.end(); iterator++) {
        if (_event.keyboardKey == iterator->keyboardKey && _event.eventType == EventType::PRESSED)
            return;
        if (_event.keyboardKey == iterator->keyboardKey && _event.eventType == EventType::REALEASED) {
            _events.erase(iterator);
            return;
        }
    }
    if (_event.eventType != EventType::UNKNOWN_TYPE && _event.eventType != EventType::REALEASED)
        _events.push_back(_event);
}

std::vector<RTypeEvent> Input::getInput(const sf::Event &event)
{
    _event.keyboardKey = Device::KeyBoardKey::UNKNOWN_KEYBOARD_KEY;
    _event.mouseKey = Device::MouseKey::UNKNOWN_MOUSE_KEY;
    _event.eventType = EventType::UNKNOWN_TYPE;
    bindEventType(event);
    bindKeyboardKey(event);
    bindMouseKey(event);
    updateEvents();
    return (_events);
}
