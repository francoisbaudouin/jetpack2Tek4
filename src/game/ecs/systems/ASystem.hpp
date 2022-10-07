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
        ASystem();
        ~ASystem();

      protected:
        std::unordered_map<size_t, std::shared_ptr<ecs::Entity>> _entityMap;

      private:
    };
} // namespace ecs

#endif /* !ASYSTEM_HPP_ */
