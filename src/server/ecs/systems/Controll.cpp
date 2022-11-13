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

void Controll::run(const std::string &sceneName, const std::vector<RTypeEvent> &rTypeEvents, const size_t entityId)
{
    if (_manager->getEntityManager(sceneName).getNumberEntities() == 0)
        return;
    if (_manager->getEntityManager(sceneName).getEntity(entityId).hasComponent<Controllable>()
        && _manager->getEntityManager(sceneName).getEntity(entityId).hasComponent<Velocity>()) {
        Velocity &velocity = _manager->getEntityManager(sceneName).getEntity(entityId).getComponent<Velocity>();
        Controllable &controllable =
            _manager->getEntityManager(sceneName).getEntity(entityId).getComponent<Controllable>();
        keyReaction(sceneName, velocity, controllable, rTypeEvents, entityId);
    }
}

void Controll::run(const std::string &sceneName, const std::string event, const size_t entityId)
{
    if (_manager->getEntityManager(sceneName).getNumberEntities() == 0)
        return;
    if (_manager->getEntityManager(sceneName).getEntity(entityId - 1).hasComponent<Controllable>()
        && _manager->getEntityManager(sceneName).getEntity(entityId - 1).hasComponent<Velocity>()) {
        Velocity &velocity = _manager->getEntityManager(sceneName).getEntity(entityId - 1).getComponent<Velocity>();
        Controllable &controllable =
            _manager->getEntityManager(sceneName).getEntity(entityId - 1).getComponent<Controllable>();
        keyReaction(sceneName, velocity, controllable, event, entityId - 1);
    }
}

void Controll::keyReaction(const std::string &sceneName, Velocity &velocity, Controllable &controllable,
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
            case Controlls::FIRE: _manager->getSystem<Fire>().run(sceneName, entityId); continue;
            default: velocity.setVelocity(none, none); continue;
        }
    }
    velocity.setVelocity(velocityValueX, velocityValueY);
}

void Controll::keyReaction(const std::string &sceneName, Velocity &velocity, Controllable &controllable,
    const std::string event, const size_t entityId)
{
    float velocityValueX = 0;
    float velocityValueY = 0;
    float velocityValue = 0.075;
    float none = 0;
    std::string orders = event;
    std::string order = orders.substr(0, orders.find_first_of(' '));

    while (!order.empty()) {
        order = orders.substr(0, orders.find_first_of(' '));
        if (order == "up")
            velocityValueY -= velocityValue;
        if (order == "down")
            velocityValueY += velocityValue;
        if (order == "left")
            velocityValueX -= velocityValue;
        if (order == "right")
            velocityValueX += velocityValue;
        if (order == "fire")
            _manager->getSystem<Fire>().run(sceneName, entityId);
        if (order != "up" && order != "down" && order != "left" && order != "right" && order != "fire") {
            velocity.setVelocity(none, none);
        }
        orders = orders.substr(orders.find_first_of(' ') + 1);
    }
    velocity.setVelocity(velocityValueX, velocityValueY);
}
