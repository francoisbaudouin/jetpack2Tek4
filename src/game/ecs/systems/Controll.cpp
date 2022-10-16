/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Controll
*/

#include "Controll.hpp"

using namespace ecs;

Controll::Controll(std::shared_ptr<Ecs> &manager) : ASystem(manager) {}

Controll::~Controll() {}

void Controll::keyReaction(Velocity &velocity, Controllable &controllable, const std::vector<RTypeEvent> &rTypeEvents)
{
    float velocityValueX = 0;
    float velocityValueY = 0;
    float velocityValue = 0.075;
    float none = 0;

    for (auto iterator = rTypeEvents.begin(); iterator < rTypeEvents.end(); iterator++) {
        switch (controllable.getAssociatedControll(iterator->keyboardKey)) {
            case Controlls::UP: velocityValueY -= velocityValue; continue;
            case Controlls::RIGHT: velocityValueX += velocityValue; continue;
            case Controlls::LEFT: velocityValueX -= velocityValue; continue;
            case Controlls::DOWN: velocityValueY += velocityValue; continue;
            case Controlls::FIRE: _manager->getSystem<Fire>().run(0); continue;
            default: velocity.setVelocity(none, none); continue;
        }
    }
    velocity.setVelocity(velocityValueX, velocityValueY);
}

void Controll::run(const std::vector<RTypeEvent> &rTypeEvents)
{
    if (_manager->getNumberEntities() == 0)
        return;
    for (auto &entity : _manager->getEntities()) {
        if (entity.second->hasComponent<Controllable>() && entity.second->hasComponent<Velocity>()) {
            Velocity &velocity = entity.second->getComponent<Velocity>();
            Controllable &controllable = entity.second->getComponent<Controllable>();
            keyReaction(velocity, controllable, rTypeEvents);
        }
    }
}
