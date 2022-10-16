/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Fire
*/

#ifndef FIRE_HPP_
#define FIRE_HPP_

#include <utility>
#include "../components/Drawable.hpp"
#include "../components/Position.hpp"
#include "../components/Velocity.hpp"
#include "../components/Weapon.hpp"
#include "../components/HitBox.hpp"

#include "ColliderReaction.hpp"
#include "ASystem.hpp"
#include "SFML/Graphics.hpp"
#include <chrono>
#include <ctime>

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
         * @brief fire a projectile one time respecting the fireRate weapon's property
         * 
         * @param entityId Id of the entity that triggered the fire system
         */
        void run(const size_t entityId);

      protected:
      private:
        std::chrono::time_point<std::chrono::system_clock> _lastTimeTriggered;
        std::chrono::time_point<std::chrono::system_clock> _triggeredTime;
        std::chrono::duration<double> _elapsedTime;
        sf::Texture _tempTexture;
    };
} // namespace ecs

#endif /* !FIRE_HPP_ */
