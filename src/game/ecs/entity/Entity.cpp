/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Entity
*/

#include "Entity.hpp"

using namespace ecs;

Entity::Entity(const size_t id) { _id = id; }

Entity::~Entity() {}

template <class Component, typename... CompArgs> Component &Entity::addComponent(CompArgs &&...args)
{
    Component *comp(new Component(std::forward<CompArgs>(args)...));

    _comps.insert({std::type_index(typeid(Component)), comp});
    return (*comp);
}

template <class Component> bool Entity::hasComponent() const
{
    return (_comps.contains(std::type_index(typeid(Component))));
}

template <class Component> Component &Entity::getComponent()
{
    auto *comp = std::any_cast<Component *>(_comps.at(std::type_index(typeid(Component))));
    return (*comp);
}

template <class Component> void Entity::removeComponent()
{
    if (!_comps.contains(std::type_index(typeid(Component))))
        return;
    _comps.erase(std::type_index(typeid(Component)));
}

size_t Entity::getId() { return (_id); }
