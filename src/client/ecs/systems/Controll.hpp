/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Controll
*/

#ifndef CONTROLL_HPP_
#define CONTROLL_HPP_

#include <vector>
#include "../components/Controllable.hpp"
#include "../components/Velocity.hpp"
#include "../enums/controlls.hpp"
#include "ASystem.hpp"
#include "Fire.hpp"

namespace ecs
{
    class Controll : public ASystem {
      public:
        /**
         * @brief Contruct a Controll system interpret Rtype's events and link it to the controllable entity
         *
         * @param manager reference to the game's entity map
         **/
        Controll(std::shared_ptr<Ecs> &manager);
        ~Controll();
        /**
         * @brief run the system
         *
         * @param sceneName : Name of the scene to select the entityManager related
         * @param controll RType events vector
         * @param entityId id of the controllable entity
         **/
        void run(const std::string &sceneName, const std::vector<RTypeEvent> &controll, const size_t entityId);

      private:
        /**
         * @brief private function that react to the rTypeEvents vector
         *
         * @param velocity actual velocity of the entity
         * @param controllable controllabe component that contains key --> event biding
         * @param rTypeEvents events vector
         * @param entityId the controllable entity id
         *
         */
        void keyReaction(const std::string &sceneName, Velocity &velocity, Controllable &controllable,
            const std::vector<RTypeEvent> &rTypeEvents, const size_t entityId);
    };
} // namespace ecs

#endif /* !CONTROLL_HPP_ */
