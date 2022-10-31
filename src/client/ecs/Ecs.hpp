/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Ecs
*/

#ifndef ECS_HPP_
#define ECS_HPP_

#include <memory>
#include "entity/EntityManager.hpp"
#include "systems/ISystem.hpp"

namespace ecs
{
    class Ecs {
      public:
        Ecs();

        ~Ecs();

        //              ENTITY MANAGEMENT
        /**
         * @brief Create a Entity Manager for the scene specified by it's Id
         * 
         * @param sceneId : id of the scene using the manager
         * @return EntityManager& : reference to the newly created manager
         */
        EntityManager &createEntityManager(const size_t sceneId);
        /**
         * @brief Get the Entity Manager for the scene specified by it's Id
         * 
         * @param sceneId : id of the scene using the manager
         * @return EntityManager& : reference to the manager needed
         */
        EntityManager &getEntityManager(const size_t sceneId);
        /**
         * @brief destroy all managers
         * 
         */
        void clearEntityManagers();
        
        //              SYSTEM MANAGEMENT
        /**
         * @brief add a system to the ecs from the type specified, exception is thrown if the system already exist
         *
         * @tparam System : type of the system
         * @param manager : shared_ptr to the ecs
         */
        template <class System> void createSystem(std::shared_ptr<Ecs> &manager)
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
        std::unordered_map<size_t, EntityManager *> _entityManagers;
        std::unordered_map<std::type_index, ISystem *> _systems;
    };
} // namespace ecs

#endif /* !ECS_HPP_ */
