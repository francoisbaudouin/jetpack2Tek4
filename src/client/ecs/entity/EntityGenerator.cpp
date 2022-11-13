/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** EntityGenerator
*/

#include "EntityGenerator.hpp"
#include "componentAdder.hpp"

#include "../components/Position.hpp"
#include "../components/Type.hpp"

namespace ecs
{
    static std::map<std::string, std::vector<std::string>> types = {
        {"Player", {"Controllable", "HitBox", "Velocity", "Weapon", "DrawbleServerSide"}},
        {"Enemy", {"HitBox", "Velocity", "DrawbleServerSide"}},
        {"PlayerProjectile", {"HitBox", "Velocity", "DrawbleServerSide"}},
        {"Placeholder", {"HitBox", "TextBox", "Selectable", "Text", "Clickable"}},
        {"Button", {"HitBox", "Clickable", "Text"}},
        {"Wall", {"HitBox"}}, {"Default", {}}};

    static std::map<std::string, functionType> componentAdder = {
        {"Controllable", addControllable},
        {"HitBox", addHitBox},
        {"Velocity", addVelocity},
        {"Weapon", addWeapon},
        {"TextBox", addTextBox},
        {"Clickable", addClickable},
        {"Text", addText},
        {"Selectable", addSelectable},
        {"DrawbleServerSide", addDrawableServer},
    };

    void addPattern(Entity &entity, const std::string &component) { componentAdder[component](entity); }

    size_t generateEntity(EntityManager &manager, const std::string &type)
    {
        Entity &entity = manager.createEntity();

        entity.addComponent<Type>(type);
        entity.addComponent<Position>(0, 0);
        for (auto iterator : types[type])
            addPattern(entity, iterator);
        return (entity.getId());
    }
    size_t generateEntity(EntityManager &manager, const std::string &type, const size_t id)
    {
        Entity &entity = manager.createEntity(id);

        entity.addComponent<Type>(type);
        entity.addComponent<Position>(0, 0);
        for (auto iterator : types[type])
            addPattern(entity, iterator);
        return (entity.getId());
    }
} // namespace ecs
