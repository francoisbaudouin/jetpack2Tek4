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

using namespace ecs;

static std::unordered_map<std::string, std::vector<std::string>> types = {
    {"Player", {"Controllable", "HitBox", "Velocity", "Weapon"}}, {"Enemy", {"HitBox", "Velocity"}},
    {"PlayerProjectile", {"HitBox", "Velocity"}},
    {"Placeholder", {"HitBox", "TextBox", "Selectable", "Text", "Clickable"}},
    {"Button", {"HitBox", "Clickable", "Text"}},
    {"Default", {}}};

static std::unordered_map<std::string, functionType> componentAdder = {
    {"Controllable", addControllable},
    {"HitBox", addHitBox},
    {"Velocity", addVelocity},
    {"Weapon", addWeapon},
    {"TextBox", addTextBox},
    {"Clickable", addClickable},
    {"Text", addText},
    {"Selectable", addSelectable},
};

EntityGenerator::EntityGenerator() {}

EntityGenerator::~EntityGenerator() {}

void EntityGenerator::addComponent(Entity &entity, const std::string &component) { componentAdder[component](entity); }

size_t EntityGenerator::createEntity(EntityManager &manager, const std::string &type)
{
    Entity &entity = manager.createEntity();

    entity.addComponent<Type>(type);
    entity.addComponent<Position>(0, 0);
    for (auto iterator : types[type])
        this->addComponent(entity, iterator);
    return (entity.getId());
}

size_t EntityGenerator::createEntity(EntityManager &manager, const std::string &type, const size_t id)
{
    Entity &entity = manager.createEntity(id);

    entity.addComponent<Type>(type);
    entity.addComponent<Position>(0, 0);
    for (auto iterator : types[type])
        this->addComponent(entity, iterator);
    return (entity.getId());
}