/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** ASystem
*/

#ifndef ASYSTEM_HPP_
#define ASYSTEM_HPP_

#include <memory>
#include <unordered_map>
#include "../Ecs.hpp"
#include "ISystem.hpp"

namespace ecs
{
    class ASystem : public ISystem {
      public:
        /**
         * @brief Abstract class for systems
         * @param manager reference to the game's entity map
         **/
        ASystem(std::shared_ptr<Ecs> &manager);
        ~ASystem();

        /**
         * @brief run the system
         **/
        void run() override;

      protected:
        std::shared_ptr<Ecs> _manager;

      private:
    };
} // namespace ecs

#endif /* !ASYSTEM_HPP_ */
