/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** EnemyWave
*/

#include <cstdlib>
#include <ctime>

#include "../ecs/components/Position.hpp"
#include "../ecs/components/Velocity.hpp"
#include "../ecs/components/AnimationFrame.hpp"
#include "../ecs/entity/EntityGenerator.hpp"
#include "EnemyWave.hpp"

using namespace rtype;

EnemyWave::EnemyWave() : _entitiesId() { std::srand(std::time(nullptr)); }

EnemyWave::~EnemyWave() {}

void EnemyWave::spawn(size_t nbEnemies, ecs::EntityManager &manager)
{
    while (nbEnemies > 0) {
        _entitiesId.push_back(ecs::generateEntity(manager, "Enemy"));
        ecs::Entity &entity = manager.getEntity(_entitiesId.back());
        entity.getComponent<ecs::Position>().setPosition(640, std::rand() % 250 + 50);
        entity.getComponent<ecs::Velocity>().setX(std::rand() % 5 * -1 - 2);
        entity.addComponent<ecs::AnimationFrame>();
        nbEnemies--;
    }
}

bool EnemyWave::checkDead() { return (_entitiesId.empty()); }