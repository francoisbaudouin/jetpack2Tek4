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
#include "systems/ISystem.hpp"

namespace ecs
{
    class Ecs {
      public:
        Ecs();

        ~Ecs();

        //              ENTITY MANAGEMENT
        Entity &createEntity();

        Entity &addEntity(const Entity &entity);

        Entity &getEntity(const size_t id);

        std::unordered_map<size_t, std::shared_ptr<Entity>> &getEntities();

        void removeEntity(const size_t id);

        size_t getNumberEntities() const;

        //              SYSTEM MANAGEMENT
        template <class System> void addSystem(std::shared_ptr<Ecs> &manager)
        {
            if (_systems.contains(std::type_index(typeid(System))))
                throw SystemAlreadyExisting();

            _systems.insert({std::type_index(typeid(System)), new System(manager)});
        }

        template <class System> System &getSystem()
        {
            if (!_systems.contains(std::type_index(typeid(System))))
                throw SystemNotExisting();
            return (*static_cast<System *>(_systems.at(std::type_index(typeid(System)))));
        }

        void clearSystems();

      private:
        std::unordered_map<size_t, std::shared_ptr<Entity>> _entities;

        std::unordered_map<std::type_index, ISystem *> _systems;
    };
} // namespace ecs

#endif /* !ECS_HPP_ */
