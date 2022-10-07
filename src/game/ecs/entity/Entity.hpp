/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Entity
*/

#ifndef __ENTITY__
#define __ENTITY__

#include <any>
#include <array>
#include <iostream>
#include <memory>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>

namespace ecs
{
    class Entity {
      public:
        Entity(const size_t);
        ~Entity();

        template <class Component, typename... ComponentArguments> Component &addComponent(ComponentArguments &&...arguments)
        {
            Component *component(new Component(std::forward<ComponentArguments>(arguments)...));

            _components.insert({std::type_index(typeid(Component)), component});
            return (*component);
        }

        template <class Component> bool hasComponent() const
        {
            return (_components.contains(std::type_index(typeid(Component))));
        }

        template <class Component> Component &getComponent()
        {
            Component *component = std::any_cast<Component *>(_components.at(std::type_index(typeid(Component))));
            return (*component);
        }

        template <class Component> Component &replaceComponent(const Component &component)
        {
            // if (!_components.contains(std::type_index(typeid(Component))))
            //     return;
            _components.erase(std::type_index(typeid(Component)));
        }

        template <class Component> void removeComponent();

        size_t getId();

      private:
        std::unordered_map<std::type_index, std::any> _components;
        size_t _id;
    };
} // namespace ecs
#endif //__ENTITY__
