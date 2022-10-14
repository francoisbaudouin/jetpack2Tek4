/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Ecs
*/

#ifndef ECS_HPP_
#define ECS_HPP_

#include <memory>
#include "entity/Entity.hpp"

namespace ecs
{
    class Ecs {
      public:
        Ecs();

        ~Ecs();

        Entity &createEntity();

        Entity &addEntity(const Entity &entity);

        Entity &getEntity(const size_t id);

        std::unordered_map<size_t, std::shared_ptr<Entity>> &getEntities();

        void removeEntity(const size_t id);

        size_t getNumberEntities() const;

      private:
        std::unordered_map<size_t, std::shared_ptr<Entity>> _entities;
    };
} // namespace ecs

#endif /* !ECS_HPP_ */
;