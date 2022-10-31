/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** ColliderReaction
*/

#include "ColliderReaction.hpp"

using namespace ecs;

static void projectileHitEnnemy(const size_t sceneId, std::shared_ptr<Ecs> &manager, Entity &entity1, Entity &entity2)
{
    manager->getEntityManager(sceneId).removeEntity(entity1.getId());
    manager->getEntityManager(sceneId).removeEntity(entity2.getId());
}

static void projectileHitWall(const size_t sceneId, std::shared_ptr<Ecs> &manager, Entity &entity1, Entity &entity2)
{
    (void)entity2;
    manager->getEntityManager(sceneId).removeEntity(entity1.getId());
}

static void playerHitWall(const size_t sceneId, std::shared_ptr<Ecs> &manager, Entity &entity1, Entity &entity2)
{
    (void)entity2;
    auto &playerPosition = manager->getEntityManager(sceneId).getEntity(entity1.getId()).getComponent<Position>();
    auto &playerVelocity = manager->getEntityManager(sceneId).getEntity(entity1.getId()).getComponent<Velocity>();

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
    _reactionMap[std::make_pair<entityType, entityType>(entityType::ENEMY, entityType::PROJECTILE)] =
        &projectileHitEnnemy;
    _reactionMap[std::make_pair<entityType, entityType>(entityType::PLAYER, entityType::WALL)] = &playerHitWall;
    _reactionMap[std::make_pair<entityType, entityType>(entityType::PROJECTILE, entityType::WALL)] = &projectileHitWall;
}

void ColliderReaction::run(const size_t sceneId, const size_t entityId1, const size_t entityId2)
{
    if (_manager->getEntityManager(sceneId).getEntities().contains(entityId1) && _manager->getEntityManager(sceneId).getEntities().contains(entityId2)) {
        auto &entity1 = _manager->getEntityManager(sceneId).getEntity(entityId1);
        auto &entity2 = _manager->getEntityManager(sceneId).getEntity(entityId2);
        std::pair pairType = std::make_pair<entityType, entityType>(
            entity1.getComponent<Type>().getEntityType(), entity2.getComponent<Type>().getEntityType());
        std::pair reversedPairType = std::make_pair<entityType, entityType>(
            entity2.getComponent<Type>().getEntityType(), entity1.getComponent<Type>().getEntityType());
        if (_reactionMap.contains(pairType)) {
            _reactionMap.at(pairType)(sceneId, _manager, entity1, entity2);
        } else if (_reactionMap.contains(reversedPairType)) {
            _reactionMap.at(reversedPairType)(sceneId, _manager, entity2, entity1);
        }
    }
}

ColliderReaction::~ColliderReaction() {}
