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
         * @brief Contruct a Controll system interpret Rtype's events and link it to controllable entity
         * @param manager reference to the game's entity map
         **/
        Controll(std::shared_ptr<Ecs> &manager);
        ~Controll();

        /**
         * @brief run the system
         * @param controll RType events vector
         **/
        void run(const std::vector<RTypeEvent> &controll);

      protected:
      private:
      /**
       * @brief private function that react to the rTypeEvents vector
       * 
       * @param velocity actual velocity of the entity
       * @param controllable controllabe component that contains key --> event biding
       * @param rTypeEvents events vector
       */
        void keyReaction(Velocity &velocity, Controllable &controllable, const std::vector<RTypeEvent> &rTypeEvents);

    };
} // namespace ecs

#endif /* !CONTROLL_HPP_ */
