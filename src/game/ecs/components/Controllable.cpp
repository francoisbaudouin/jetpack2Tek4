/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Controllable
*/

#include "Controllable.hpp"

using namespace ecs;

Controllable::Controllable(const size_t entityId, const std::pair<Device::KeyBoardKey, Controlls> &upControll,
    const std::pair<Device::KeyBoardKey, Controlls> &rightControll,
    const std::pair<Device::KeyBoardKey, Controlls> &leftControll,
    const std::pair<Device::KeyBoardKey, Controlls> &downControll)
    : AComponent(entityId)
{
    _controllMap = {upControll, rightControll, leftControll, downControll};
}

Controllable::~Controllable() {}

Controlls Controllable::getAssociatedControll(Device::KeyBoardKey key)
{
    if (key == Device::KeyBoardKey::UNKNOWN_KEYBOARD_KEY) {
        return Controlls::UNDEFINED;
    }
    return _controllMap[key];
}
