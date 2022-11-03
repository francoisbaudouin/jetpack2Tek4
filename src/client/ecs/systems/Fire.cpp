/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Fire
*/

#include "Fire.hpp"

using namespace ecs;

Fire::Fire(std::shared_ptr<Ecs> &manager) : ASystem(manager)
{
    _lastTimeTriggered = std::chrono::system_clock::now();
    _tempTexture.loadFromFile("src/game/assets/projecktile.png");
}

Fire::~Fire() {}

void Fire::createProjectile(const size_t sceneId, const size_t entityId)
{
    Position &position = _manager->getEntityManager(sceneId).getEntity(entityId).getComponent<Position>();
    auto &projectile = _manager->getEntityManager(sceneId).createEntity();
    projectile.addComponent<Position>(position.getX(), position.getY());
    projectile.addComponent<Drawable>(_tempTexture);
    projectile.addComponent<Velocity>(0.3, 0.0);
    projectile.addComponent<HitBox>(32, 10);
    projectile.addComponent<Type>("projectile");
    _lastTimeTriggered = _triggeredTime;
}

void Fire::run(const size_t sceneId, const size_t entityId)
{
    _triggeredTime = std::chrono::system_clock::now();
    _elapsedTime = _triggeredTime - _lastTimeTriggered;
    if (_manager->getEntityManager(sceneId).getEntity(entityId).hasComponent<Weapon>()
        && _manager->getEntityManager(sceneId).getEntity(entityId).hasComponent<Position>()) {
        Weapon &weapon = _manager->getEntityManager(sceneId).getEntity(entityId).getComponent<Weapon>();
        if (_elapsedTime.count() >= weapon.getFireRate())
            createProjectile(sceneId, entityId);
    }
}
