/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** EntityGenerator
*/

#ifndef ENTITYGENERATOR_HPP_
#define ENTITYGENERATOR_HPP_

#include <functional>

#include "EntityManager.hpp"

namespace ecs
{
    using functionType = std::function<void(Entity &)>;

    /**
     * @brief add the component specified to the entity passed as parameter
     *
     * @param entity : entity that need the component
     * @param component : component to add
     */
    void addPattern(Entity &entity, const std::string &component);
    /**
     * @brief Create an Entity and add components needed by the type
     *
     * @param manager : manager that will get the new entity
     * @param type : type of the entity to create
     * @return size_t : id of the newly created entity
     */
    size_t generateEntity(EntityManager &manager, const std::string &type);
    /**
     * @brief Create an Entity and add components needed by the type
     *
     * @param manager : manager that will get the new entity
     * @param type : type of the entity to create
     * @param id : specify the id of the entity
     * @return size_t : id of the newly created entity
     */
    size_t generateEntity(EntityManager &manager, const std::string &type, const size_t id);
} // namespace ecs

#endif /* !ENTITYGENERATOR_HPP_ */
