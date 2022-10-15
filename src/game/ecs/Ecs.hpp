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
        /**
         * @brief Create an Entity object
         *
         * @return Entity& : entity that was created
         */
        Entity &createEntity();

        /**
         * @brief add existing entity, exception is thrown if the entity exist already
         *
         * @param entity : entity to add
         * @return Entity& : entity that was added in the ecs
         */
        Entity &addEntity(const Entity &entity);

        /**
         * @brief Get an entity from it's id, exception is thrown if the entity doesn't exist
         *
         * @param id : id of the entity to get
         * @return Entity& : entity in question
         */
        Entity &getEntity(const size_t id);

        /**
         * @brief Get the map of the entities
         *
         * @return std::unordered_map<size_t, std::shared_ptr<Entity>>& : map of the entities
         */
        std::unordered_map<size_t, std::shared_ptr<Entity>> &getEntities();

        /**
         * @brief remove an entity from the map, exception is thrown if the entity doesn't exist
         *
         * @param id : id of the entity to remove
         */
        void removeEntity(const size_t id);

        /**
         * @brief Get the number of entities stocked in the ecs
         *
         * @return size_t : number of entities
         */
        size_t getNumberEntities() const;

        //              SYSTEM MANAGEMENT
        /**
         * @brief add a system to the ecs from the type specified, exception is thrown if the system already exist
         *
         * @tparam System : type of the system
         * @param manager : shared_ptr to the ecs
         */
        template <class System> void addSystem(std::shared_ptr<Ecs> &manager)
        {
            if (_systems.contains(std::type_index(typeid(System))))
                throw SystemAlreadyExisting();

            _systems.insert({std::type_index(typeid(System)), new System(manager)});
        }

        /**
         * @brief Get a system from the type specified, exception is thrown if the system doesn't exist
         *
         * @tparam System : type of the system
         * @return System& : system to return
         */
        template <class System> System &getSystem()
        {
            if (!_systems.contains(std::type_index(typeid(System))))
                throw SystemNotExisting();
            return (*static_cast<System *>(_systems.at(std::type_index(typeid(System)))));
        }

        /**
         * @brief clear the system stocke in the ecs
         *
         */
        void clearSystems();

      private:
        std::unordered_map<size_t, std::shared_ptr<Entity>> _entities;

        std::unordered_map<std::type_index, ISystem *> _systems;
    };
} // namespace ecs

#endif /* !ECS_HPP_ */
