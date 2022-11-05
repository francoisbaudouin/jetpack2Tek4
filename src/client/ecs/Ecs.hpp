/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Ecs
*/

#ifndef ECS_HPP_
#define ECS_HPP_

#include <memory>
#include "../TextureDatabase.hpp"
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
         * @param sceneName : Name of the scene using the manager
         * @return EntityManager& : reference to the newly created manager
         */
        EntityManager &createEntityManager(const std::string sceneName);
        /**
         * @brief Get the Entity Manager for the scene specified by it's Id
         *
         * @param sceneName : Name of the scene using the manager
         * @return EntityManager& : reference to the manager needed
         */
        EntityManager &getEntityManager(const std::string sceneName);
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
            System *system;

            if (_systems.contains(std::type_index(typeid(System))))
                throw SystemAlreadyExisting(typeid(System).name());

            system = new System(manager);
            if (dynamic_cast<ISystem *>(system))
                _systems.insert({std::type_index(typeid(System)), system});
            else {
                delete system;
                throw SystemNotCompatible(typeid(System).name());
            }
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
                throw SystemNotExisting(typeid(System).name());
            return (*static_cast<System *>(_systems.at(std::type_index(typeid(System)))));
        }

        /**
         * @brief clear the system stocke in the ecs
         *
         */
        void clearSystems();

      private:
        std::shared_ptr<rtype::TextureDatabase> _textureDatabase;
        std::unordered_map<std::string, EntityManager *> _entityManagers;
        std::unordered_map<std::type_index, ISystem *> _systems;
    };
} // namespace ecs

#endif /* !ECS_HPP_ */
