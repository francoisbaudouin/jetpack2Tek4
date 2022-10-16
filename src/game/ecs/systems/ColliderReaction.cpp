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

void enemyCollidePlayer(std::shared_ptr<Ecs> &manager, Entity &entity1, Entity &entity2) {}

void undefinedReaction(std::shared_ptr<Ecs> &manager, Entity &entity1, Entity &entity2)
{
    std::cout << "undefined reaction" << std::endl;
}

ColliderReaction::ColliderReaction(std::shared_ptr<Ecs> manager) : ASystem(manager), _reactionMap()
{
    _reactionMap[std::make_pair<entityType, entityType>(
        entityType::UNDEFINED_ENTITY_TYPE, entityType::UNDEFINED_ENTITY_TYPE)] = &undefinedReaction;
    _reactionMap[std::make_pair<entityType, entityType>(entityType::ENEMY, entityType::PROJECTILE)] =
        &projectileHitEnnemy;
    _reactionMap[std::make_pair<entityType, entityType>(entityType::ENEMY, entityType::PLAYER)] = &enemyCollidePlayer;
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
