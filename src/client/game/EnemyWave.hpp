/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** EnemyWave
*/

#ifndef ENEMYWAVE_HPP_
#define ENEMYWAVE_HPP_

#include <vector>
#include <iostream>

#include "../ecs/entity/EntityManager.hpp"

namespace rtype
{
    class EnemyWave {
      public:
        EnemyWave();
        ~EnemyWave();

        void spawn(const size_t nbEnemies, ecs::EntityManager &manager);

        bool checkDead();

      private:
        std::vector<size_t> _entitiesId;
    };
} // namespace ecs

#endif /* !ENEMYWAVE_HPP_ */
