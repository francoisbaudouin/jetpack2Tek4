/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Entity
*/

#include "Entity.hpp"
#include "components/AComponent.hpp"
#include "components/Controllable.hpp"
#include "components/Drawable.hpp"
#include "components/Position.hpp"
#include "components/Velocity.hpp"

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

// template <class Component>
// Component &Entity::replaceComponent(const Component &comp)
// {
//   Component *newComp(new Component(comp));

//   _comps.at(std::type_index(typeid(Component))) = newComp;
//   return (*newComp);
// }

template <class Component> void Entity::removeComponent()
{
    if (!_comps.contains(std::type_index(typeid(Component))))
        return;
    _comps.erase(std::type_index(typeid(Component)));
}

size_t Entity::getId() { return (_id); }

template AComponent &Entity::addComponent<AComponent>();
template Controllable &Entity::addComponent<Controllable>();
template Drawable &Entity::addComponent<Drawable>();
template Position &Entity::addComponent<Position>();
template Velocity &Entity::addComponent<Velocity>();

template bool Entity::hasComponent<AComponent>() const;
template bool Entity::hasComponent<Controllable>() const;
template bool Entity::hasComponent<Drawable>() const;
template bool Entity::hasComponent<Position>() const;
template bool Entity::hasComponent<Velocity>() const;

template AComponent &Entity::getComponent<AComponent>();
template Controllable &Entity::getComponent<Controllable>();
template Drawable &Entity::getComponent<Drawable>();
template Position &Entity::getComponent<Position>();
template Velocity &Entity::getComponent<Velocity>();

// template AComponent &Entity::replaceComponent<AComponent>(const AComponent &);
// template Controllable &Entity::replaceComponent<Controllable>(const Controllable &);
// template Drawable &Entity::replaceComponent<Drawable>(const Drawable &);
// template Position &Entity::replaceComponent<Position>(const Position &);
// template Velocity &Entity::replaceComponent<Velocity>(const Velocity &);

template void Entity::removeComponent<AComponent>();
template void Entity::removeComponent<Controllable>();
template void Entity::removeComponent<Drawable>();
template void Entity::removeComponent<Position>();
template void Entity::removeComponent<Velocity>();
