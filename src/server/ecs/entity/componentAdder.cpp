/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** componentAdder
*/

#include <map>

#include "componentAdder.hpp"

#include "../components/Clickable.hpp"
#include "../components/Controllable.hpp"
#include "../components/HitBox.hpp"
#include "../components/Selectable.hpp"
#include "../components/Text.hpp"
#include "../components/TextBox.hpp"
#include "../components/Velocity.hpp"
#include "../components/Weapon.hpp"

#include "../enums/event.hpp"
#include "../enums/weapons.hpp"

namespace ecs
{
    void addControllable(Entity &entity)
    {
        entity.addComponent<Controllable>(Device::Z, Device::D, Device::Q, Device::S, Device::SPACE);
    }

    void addHitBox(Entity &entity) { entity.addComponent<HitBox>(0, 0); }

    void addVelocity(Entity &entity) { entity.addComponent<Velocity>(0, 0); }

    void addTextBox(Entity &entity) { entity.addComponent<TextBox>(); }

    void addWeapon(Entity &entity) { entity.addComponent<Weapon>(0, 0, ecs::UNDEFINED_WEAPON_TYPE); }

    void addClickable(Entity &entity) { entity.addComponent<Clickable>(); }

    void addText(Entity &entity) { entity.addComponent<Text>(); }

    void addSelectable(Entity &entity) { entity.addComponent<Selectable>(); }
} // namespace ecs