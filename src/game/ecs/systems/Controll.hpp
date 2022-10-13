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
#include "../components/Position.hpp"
#include "../components/Velocity.hpp"
#include "../enums/controlls.hpp"
#include "ASystem.hpp"

namespace ecs
{
    class Controll : public ASystem {
      public:
        /**
         * @brief Contruct a Controll system interpret Rtype's events and link it to controllable entity
         * @param entityMap reference to the game's entity map
         **/
        Controll(std::unordered_map<size_t, std::shared_ptr<ecs::Entity>> &entityMap);
        ~Controll();

        /**
         * @brief run the system
         * @param controll RType events vector
         **/
        void run(std::vector<RTypeEvent> controll);

      protected:
      private:
    };
} // namespace ecs

#endif /* !CONTROLL_HPP_ */
