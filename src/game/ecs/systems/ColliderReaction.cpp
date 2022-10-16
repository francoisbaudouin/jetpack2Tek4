/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** ColliderReaction
*/

#include "ColliderReaction.hpp"

using namespace ecs;

static void projectileHitEnnemy(std::shared_ptr<Ecs> &manager, Entity &entity1, Entity &entity2)
{
    manager->removeEntity(entity1.getId());
    manager->removeEntity(entity2.getId());
}

static void projectileHitWall(std::shared_ptr<Ecs> &manager, Entity &entity1, Entity &entity2)
{
    manager->removeEntity(entity1.getId());
}

static void playerHitWall(std::shared_ptr<Ecs> &manager, Entity &entity1, Entity &entity2)
{
    auto &playerPosition = manager->getEntity(entity1.getId()).getComponent<Position>();
    auto &playerVelocity = manager->getEntity(entity1.getId()).getComponent<Velocity>();

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
    _reactionMap[std::make_pair<entityType, entityType>(entityType::PLAYER, entityType::WALL)] =
        &playerHitWall;
    _reactionMap[std::make_pair<entityType, entityType>(entityType::PROJECTILE, entityType::WALL)] =
        &projectileHitWall;
}

void ColliderReaction::run(const size_t entityId1, const size_t entityId2)
{
    if (_manager->getEntities().contains(entityId1) && _manager->getEntities().contains(entityId2)) {
        auto &entity1 = _manager->getEntity(entityId1);
        auto &entity2 = _manager->getEntity(entityId2);
        std::pair pairType = std::make_pair<entityType, entityType>(
            entity1.getComponent<Type>().getEntityType(), entity2.getComponent<Type>().getEntityType());
        std::pair reversedPairType = std::make_pair<entityType, entityType>(
            entity2.getComponent<Type>().getEntityType(), entity1.getComponent<Type>().getEntityType());
        if (_reactionMap.contains(pairType)) {
            _reactionMap.at(pairType)(_manager, entity1, entity2);
        } else if (_reactionMap.contains(reversedPairType)) {
            _reactionMap.at(reversedPairType)(_manager, entity2, entity1);
        }
    }
}

ColliderReaction::~ColliderReaction() {}
