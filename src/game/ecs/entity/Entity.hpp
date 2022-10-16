/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Entity
*/

#ifndef __ENTITY__
#define __ENTITY__

#include <typeindex>
#include <typeinfo>
#include "../components/IComponent.hpp"
#include "../exceptions/Exception.hpp"
#include <unordered_map>

namespace ecs
{
    class Entity {
      public:
        /**
         * @brief Construct a new Entity object and call the 'getNewEntityId' that generate a new id for the entity
         *
         */
        Entity();
        ~Entity();

        /**
         * @brief create a component from the type of the template
         *
         * @tparam Component : type of the component to create
         * @tparam ComponentArguments : types of the arguments needed by the component
         * @param arguments : arguments needed by the component
         * @return Component& : references to the component ceated
         */
        template <class Component, typename... ComponentArguments>
        Component &addComponent(ComponentArguments &&...arguments)
        {
            if (this->hasComponent<Component>())
                return (this->getComponent<Component>());

            Component *component(new Component(this->getId(), std::forward<ComponentArguments>(arguments)...));

            _components.insert({std::type_index(typeid(Component)), component});
            return (*component);
        }

        /**
         * @brief check if the entity has the component specified by the template
         *
         * @tparam Component : type of the component to check
         * @return true : has the component
         * @return false : doesn't has it
         */
        template <class Component> bool hasComponent() const
        {
            return (_components.contains(std::type_index(typeid(Component))));
        }

        /**
         * @brief Get the Component specified by the template
         *
         * @tparam Component : type of the component to get
         * @return Component& : reference to the component
         */
        template <class Component> Component &getComponent()
        {
            if (!this->hasComponent<Component>())
                throw ecs::NoComponent(typeid(Component).name(), this->getId());
            Component *component = static_cast<Component *>(_components.at(std::type_index(typeid(Component))));
            return (*component);
        }

        /**
         * @brief replace the component by the one passed as parameter
         *
         * @tparam Component : type of the component to replace
         * @param component : component that will replace the old one
         * @return Component& : reference to the component that replaced the old one
         */
        template <class Component> Component &replaceComponent(Component &component)
        {
            if (this->hasComponent<Component>())
                this->removeComponent<Component>();
            _components.insert({std::type_index(typeid(Component)), &component});
            return (component);
        }

        /**
         * @brief remove the Component specified by the template
         *
         * @tparam Component : type of the component to remove
         */
        template <class Component> void removeComponent()
        {
            if (!this->hasComponent<Component>())
                throw ecs::NoComponent(typeid(Component).name(), this->getId());
            delete static_cast<Component *>(_components.at(std::type_index(typeid(Component))));
            _components.erase(std::type_index(typeid(Component)));
        }

        /**
         * @brief Get the Id of the entity
         *
         * @return size_t : id of the entity
         */
        size_t getId() const;

      private:
        std::unordered_map<std::type_index, IComponent *> _components;
        size_t _id;
    };
} // namespace ecs
#endif //__ENTITY__
