/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Fire
*/

#include "Fire.hpp"

using namespace ecs;

Fire::Fire(std::shared_ptr<Ecs> &manager) : ASystem(manager) { _lastTimeTriggered = std::chrono::system_clock::now(); }

Fire::~Fire() {}

void Fire::createProjectile(const std::string &sceneName, const size_t entityId)
{
    Position &position = _manager->getEntityManager(sceneName).getEntity(entityId).getComponent<Position>();
    auto &projectile = _manager->getEntityManager(sceneName).createEntity();
    projectile.addComponent<Position>(position.getX(), position.getY());
    projectile.addComponent<DrawableServerSide>("projectile");
    projectile.addComponent<Velocity>(0.3, 0.0);
    projectile.addComponent<HitBox>(32, 10);
    projectile.addComponent<Type>("projectile");
    _lastTimeTriggered = _triggeredTime;
}

void Fire::run(const std::string &sceneName, const size_t entityId)
{
    _triggeredTime = std::chrono::system_clock::now();
    _elapsedTime = _triggeredTime - _lastTimeTriggered;
    if (_manager->getEntityManager(sceneName).getEntity(entityId).hasComponent<Weapon>()
        && _manager->getEntityManager(sceneName).getEntity(entityId).hasComponent<Position>()) {
        Weapon &weapon = _manager->getEntityManager(sceneName).getEntity(entityId).getComponent<Weapon>();
        if (_elapsedTime.count() >= weapon.getFireRate())
            createProjectile(sceneName, entityId);
    }
}
