/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Controllable
*/

#include "Controllable.hpp"

using namespace ecs;

Controllable::Controllable(const size_t entityId, const Device::KeyBoardKey &upKey, const Device::KeyBoardKey &rightKey,
    const Device::KeyBoardKey &leftKey, const Device::KeyBoardKey &downKey, const Device::KeyBoardKey &fireKey)
    : AComponent(entityId)
{
    _controllMap = {{upKey, Controlls::UP}, {rightKey, Controlls::RIGHT}, {leftKey, Controlls::LEFT},
        {downKey, Controlls::DOWN}, {fireKey, Controlls::FIRE}};
}

Controllable::~Controllable() {}

Controlls Controllable::getAssociatedControll(Device::KeyBoardKey key)
{
    if (key == Device::KeyBoardKey::UNKNOWN_KEYBOARD_KEY || !_controllMap.contains(key)) {
        return Controlls::UNDEFINED;
    }
    return _controllMap[key];
}
