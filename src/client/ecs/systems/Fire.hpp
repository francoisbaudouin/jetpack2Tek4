/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Fire
*/

#ifndef FIRE_HPP_
#define FIRE_HPP_

#include <chrono>
#include <ctime>
#include <utility>
#include "ASystem.hpp"

namespace ecs
{
    class Ecs;

    class Fire : public ASystem {
      public:
        /**
         * @brief Construct a new Fire system that fire a projectile belong to weapon component
         *
         * @param manager reference to shared_ptr of the ecs class
         */
        Fire(std::shared_ptr<Ecs> &manager);
        ~Fire();
        /**
         * @brief Create a projectile at the position of the player
         *
         * @param sceneName : Name of the scene to select the entityManager related
         * @param entityId : id of the entity that triggered the fire system
         */
        void createProjectile(const std::string &sceneName, const size_t entityId);
        /**
         * @brief fire a projectile one time respecting the fireRate weapon's property
         *
         * @param entityId : Id of the entity that triggered the fire system
         */
        void run(const std::string &sceneName, const size_t entityId);

      protected:
      private:
        std::chrono::time_point<std::chrono::system_clock> _lastTimeTriggered;
        std::chrono::time_point<std::chrono::system_clock> _triggeredTime;
        std::chrono::duration<double> _elapsedTime;
    };
} // namespace ecs

#endif /* !FIRE_HPP_ */
