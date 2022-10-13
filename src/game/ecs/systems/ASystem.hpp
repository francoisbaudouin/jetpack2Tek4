/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** ASystem
*/

#ifndef ASYSTEM_HPP_
#define ASYSTEM_HPP_

#include <memory>
#include "../entity/Entity.hpp"
#include "ISystem.hpp"
#include <unordered_map>

namespace ecs
{
    class ASystem : public ISystem {
      public:
        /**
         * @brief Abstract class for systems
         * @param entityMap reference to the game's entity map
         **/
        ASystem(std::unordered_map<size_t, std::shared_ptr<ecs::Entity>> &entityMap);
        ~ASystem();
        /**
         * run the system
         **/
        void run() override;

      protected:
        std::unordered_map<size_t, std::shared_ptr<ecs::Entity>> _entityMap;

      private:
    };
} // namespace ecs

#endif /* !ASYSTEM_HPP_ */
