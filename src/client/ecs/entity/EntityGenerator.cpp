/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** EntityGenerator
*/

#include "EntityGenerator.hpp"
#include "componentAdder.hpp"

#include "../components/Position.hpp"
#include "../components/TextBox.hpp"
#include "../components/Type.hpp"

using namespace ecs;

static std::unordered_map<std::string, std::vector<std::string>> types = {
    {"Player", {"Controllable", "HitBox", "Velocity", "Weapon"}}, {"Enemy", {"HitBox", "Velocity"}},
    {"PlayerProjectile", {"HitBox", "HitBox", "Velocity"}},
    {"Placeholder", {"HitBox", "TextBox"}},
    {"Default", {}}};

static std::unordered_map<std::string, functionType> componentAdder = {
    {"Controllable", addControllable},
    {"HitBox", addHitBox},
    {"Velocity", addVelocity},
    {"Weapon", addWeapon},
    {"TextBox", addTextBox},
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