/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** ColliderReaction
*/

#include "ColliderReaction.hpp"

using namespace ecs;

static void projectileHitEnnemy(
    const std::string sceneName, std::shared_ptr<Ecs> &manager, Entity &entity1, Entity &entity2)
{
    manager->getEntityManager(sceneName).removeEntity(entity1.getId());
    manager->getEntityManager(sceneName).removeEntity(entity2.getId());
}

static void projectileHitWall(
    const std::string sceneName, std::shared_ptr<Ecs> &manager, Entity &entity1, Entity &entity2)
{
    (void)entity2;
    manager->getEntityManager(sceneName).removeEntity(entity1.getId());
}

static void playerHitWall(const std::string sceneName, std::shared_ptr<Ecs> &manager, Entity &entity1, Entity &entity2)
{
    (void)entity2;
    auto &playerPosition = manager->getEntityManager(sceneName).getEntity(entity1.getId()).getComponent<Position>();
    auto &playerVelocity = manager->getEntityManager(sceneName).getEntity(entity1.getId()).getComponent<Velocity>();

    if (playerVelocity.getY() > 0)
        playerPosition.setY(playerPosition.getY() - 1);
    if (playerVelocity.getY() < 0)
        playerPosition.setY(playerPosition.getY() + 1);
    if (playerVelocity.getX() > 0)
        playerPosition.setX(playerPosition.getX() - 1);
    if (playerVelocity.getX() < 0)
        playerPosition.setX(playerPosition.getX() + 1);
}

ColliderReaction::ColliderReaction(std::shared_ptr<Ecs> manager) : ASystem(manager), _reactionMap()
{
    _reactionMap[std::make_pair<std::string, std::string>("Enemy", "Projectile")] = &projectileHitEnnemy;
    _reactionMap[std::make_pair<std::string, std::string>("Player", "Wall")] = &playerHitWall;
    _reactionMap[std::make_pair<std::string, std::string>("Projectile", "Wall")] = &projectileHitWall;
}

void ColliderReaction::run(const std::string sceneName, const size_t entityId1, const size_t entityId2)
{
    if (_manager->getEntityManager(sceneName).getEntities().contains(entityId1)
        && _manager->getEntityManager(sceneName).getEntities().contains(entityId2)) {
        auto &entity1 = _manager->getEntityManager(sceneName).getEntity(entityId1);
        auto &entity2 = _manager->getEntityManager(sceneName).getEntity(entityId2);
        std::pair pairType = std::make_pair<std::string, std::string>(
            entity1.getComponent<Type>().getEntityType(), entity2.getComponent<Type>().getEntityType());
        std::pair reversedPairType = std::make_pair<std::string, std::string>(
            entity2.getComponent<Type>().getEntityType(), entity1.getComponent<Type>().getEntityType());
        if (_reactionMap.contains(pairType)) {
            _reactionMap.at(pairType)(sceneName, _manager, entity1, entity2);
        } else if (_reactionMap.contains(reversedPairType)) {
            _reactionMap.at(reversedPairType)(sceneName, _manager, entity2, entity1);
        }
    }
}

ColliderReaction::~ColliderReaction() {}
