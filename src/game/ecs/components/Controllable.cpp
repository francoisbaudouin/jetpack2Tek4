/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Controllable
*/

#include "Controllable.hpp"
#include <iostream>

using namespace ecs;

Controllable::Controllable(const size_t entityId, std::pair<Device::KeyBoardKey, Controlls> upControll,
    std::pair<Device::KeyBoardKey, Controlls> rightControll, std::pair<Device::KeyBoardKey, Controlls> leftControll,
    std::pair<Device::KeyBoardKey, Controlls> downControll)
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