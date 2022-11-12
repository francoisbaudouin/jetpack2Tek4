/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** EntityManager
*/

#ifndef ENTITYMANAGER_HPP_
#define ENTITYMANAGER_HPP_

#include <memory>

#include "Entity.hpp"

namespace ecs
{
    class EntityManager {
      public:
        EntityManager();
        ~EntityManager();
        /**
         * @brief increment _id
         */
        void updateId();
        /**
         * @brief Create an Entity object
         *
         * @return Entity& : entity that was created
         */
        Entity &createEntity();
        /**
         * @brief Create a Entity object
         *
         * @param id id to specify
         * @return Entity& : entity that was created
         */
        Entity &createEntity(const size_t id);

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

      private:
        std::unordered_map<size_t, std::shared_ptr<Entity>> _entities;
        size_t _id;
    };
} // namespace ecs

#endif /* !ENTITYMANAGER_HPP_ */
