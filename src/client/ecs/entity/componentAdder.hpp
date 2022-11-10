/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** ComponentAdder
*/

#ifndef COMPONENTADDER_HPP_
#define COMPONENTADDER_HPP_

#include "Entity.hpp"

namespace ecs
{
    /**
     * @brief add the Controllable Compoenent passed as parameter
     *
     * @param entity : entity to add
     */
    void addControllable(Entity &entity);
    /**
     * @brief add the HitBox Compoenent passed as parameter
     *
     * @param entity : entity to add
     */
    void addHitBox(Entity &entity);
    /**
     * @brief add the Velocity Compoenent passed as parameter
     *
     * @param entity : entity to add
     */
    void addVelocity(Entity &entity);
    /**
     * @brief add the Weapon Compoenent passed as parameter
     *
     * @param entity : entity to add
     */
    void addWeapon(Entity &entity);
    /**
     * @brief add the TextBox Component passed as parameter
     * 
     * @param entity : entity to add
     */
    void addTextBox(Entity &entity);
    /**
     * @brief add the Clickable Component passed as parameter
     * 
     * @param entity : entity to add
     */
    void addClickable(Entity &entity);
    /**
     * @brief add the Text Component passed as parameter
     * 
     * @param entity : entity to add
     */
    void addText(Entity &entity);
    /**
     * @brief add the Selectable Component passed as parameter
     * 
     * @param entity : entity to add
     */
    void addSelectable(Entity &entity);

} // namespace ecs

#endif /* !COMPONENTADDER_HPP_ */
