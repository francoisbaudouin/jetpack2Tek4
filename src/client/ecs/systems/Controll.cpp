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

void Controll::run(const size_t sceneId, const std::vector<RTypeEvent> &rTypeEvents, const size_t entityId)
{
    if (_manager->getEntityManager(sceneId).getNumberEntities() == 0)
        return;
    if (_manager->getEntityManager(sceneId).getEntity(entityId).hasComponent<Controllable>()
        && _manager->getEntityManager(sceneId).getEntity(entityId).hasComponent<Velocity>()) {
        Velocity &velocity = _manager->getEntityManager(sceneId).getEntity(entityId).getComponent<Velocity>();
        Controllable &controllable =
            _manager->getEntityManager(sceneId).getEntity(entityId).getComponent<Controllable>();
        keyReaction(sceneId, velocity, controllable, rTypeEvents, entityId);
    }
}

void Controll::keyReaction(const size_t sceneId, Velocity &velocity, Controllable &controllable,
    const std::vector<RTypeEvent> &rTypeEvents, const size_t entityId)
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
            case Controlls::FIRE: _manager->getSystem<Fire>().run(sceneId, entityId); continue;
            default: velocity.setVelocity(none, none); continue;
        }
    }
    velocity.setVelocity(velocityValueX, velocityValueY);
}
