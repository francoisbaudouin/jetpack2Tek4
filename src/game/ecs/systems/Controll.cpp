/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Controll
*/

#include "Controll.hpp"

using namespace ecs;

Controll::Controll(std::unordered_map<size_t, std::shared_ptr<ecs::Entity>> &entityMap) : ASystem(entityMap) {}

Controll::~Controll() {}

void Controll::run(RTypeEvent rTypeEvent)
{
    if (_entityMap.size() == 0) {
        return;
    }
    for (auto entity : _entityMap) {
        if (entity.second->hasComponent<Controllable>() && entity.second->hasComponent<Velocity>()) {
            float velocityValue = 0.05;
            float none = 0;
            Velocity &velocity = entity.second->getComponent<Velocity>();
            Controllable &controllable = entity.second->getComponent<Controllable>();
            if (rTypeEvent.eventType == EventType::PRESSED) {
                switch (controllable.getAssociatedControll(rTypeEvent.keyboardKey)) {
                    case Controlls::UP: velocity.setVelocity(none, -velocityValue); break;
                    case Controlls::RIGHT: velocity.setVelocity(velocityValue, none); break;
                    case Controlls::LEFT: velocity.setVelocity(-velocityValue, none); break;
                    case Controlls::DOWN: velocity.setVelocity(none, velocityValue); break;
                    default: velocity.setVelocity(none, none); break;
                }
            } else {
                if (rTypeEvent.eventType == EventType::REALEASED)
                    velocity.setVelocity(none, none);
            }
        }
    }
}