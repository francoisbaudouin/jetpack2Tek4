/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** ASystem
*/

#ifndef ASYSTEM_HPP_
#define ASYSTEM_HPP_

#include <memory>
#include "../Ecs.hpp"
#include "ISystem.hpp"
#include <map>

namespace ecs
{
    class Ecs;
    class ASystem : public ISystem {
      public:
        /**
         * @brief Abstract class for systems
         *
         * @param manager reference to the game's entity map
         **/
        ASystem(std::shared_ptr<Ecs> &manager);
        // ecs::Ecs;
        ~ASystem();
        /**
         * @brief run the system
         *
         * @param sceneName : name of the scene to select the entityManager related
         */
        void run(const std::string &sceneName) override;

      protected:
        std::shared_ptr<Ecs> _manager;

      private:
    };
} // namespace ecs

#endif /* !ASYSTEM_HPP_ */
