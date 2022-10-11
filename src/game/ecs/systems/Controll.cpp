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

void changeVelocity(Velocity &velocity, Controllable &controllable, std::vector<RTypeEvent> rTypeEvents)
{
    float velocityValueX = 0;
    float velocityValueY = 0;
    float velocityValue = 0.075;
    float none = 0;

    for (auto iterator = rTypeEvents.begin(); iterator < rTypeEvents.end(); iterator++) {
        switch (controllable.getAssociatedControll(iterator->keyboardKey)) {
            case Controlls::UP:
                velocityValueY -= velocityValue;
                continue;
            case Controlls::RIGHT:
                velocityValueX += velocityValue;
                continue;
            case Controlls::LEFT:
                velocityValueX -= velocityValue;
                continue;
            case Controlls::DOWN:
                velocityValueY += velocityValue;
                continue;
            default: velocity.setVelocity(none, none); continue;
        }
    }
    velocity.setVelocity(velocityValueX, velocityValueY);
}

void Controll::run(std::vector<RTypeEvent> rTypeEvents)
{
    if (_entityMap.size() == 0)
        return;
    for (auto entity : _entityMap) {
        if (entity.second->hasComponent<Controllable>() && entity.second->hasComponent<Velocity>()) {
            Velocity &velocity = entity.second->getComponent<Velocity>();
            Controllable &controllable = entity.second->getComponent<Controllable>();
            changeVelocity(velocity, controllable, rTypeEvents);
        }
    }
}
