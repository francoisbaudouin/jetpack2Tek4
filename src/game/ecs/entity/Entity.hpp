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

        template <class Component, typename... CompArgs> Component &addComponent(CompArgs &&...);

        template <class Component> bool hasComponent() const;

        template <class Component> Component &getComponent();

        template <class Component> Component &replaceComponent(const Component &comp);

        template <class Component> void removeComponent();

        size_t getId();

      private:
        std::unordered_map<std::type_index, std::any> _comps;
        size_t _id;
    };
} // namespace ecs
#endif //__ENTITY__
