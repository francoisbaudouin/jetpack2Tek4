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
#include <unordered_map>

#include "../components/IComponent.hpp"
#include "../exceptions/Exception.hpp"

namespace ecs
{
    class Entity {
      public:
        /**
         * @brief Construct a new Entity object and set it's id
         *
         * @param id : id of the entity
         */
        Entity(const size_t id);
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
            Component *component;

            if (this->hasComponent<Component>())
                throw ComponentAlreadyExisting(typeid(Component).name(), _id);

            component = new Component(this->getId(), std::forward<ComponentArguments>(arguments)...);
            if (dynamic_cast<IComponent *>(component))
                _components.insert({std::type_index(typeid(Component)), component});
            else {
                delete component;
                throw ComponentNotCompatible(typeid(Component).name());
            }
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
                throw ecs::ComponentNotExisting(typeid(Component).name(), this->getId());

            return (*static_cast<Component *>(_components.at(std::type_index(typeid(Component)))));
        }

        /**
         * @brief remove the Component specified by the template
         *
         * @tparam Component : type of the component to remove
         */
        template <class Component> void removeComponent()
        {
            if (!this->hasComponent<Component>())
                throw ecs::ComponentNotExisting(typeid(Component).name(), this->getId());
            delete static_cast<Component *>(_components.at(std::type_index(typeid(Component))));
            _components.erase(std::type_index(typeid(Component)));
        }

        /**
         * @brief Get the Id of the entity
         *
         * @return size_t : id of the entity
         */
        size_t getId() const;
        /**
         * @brief Set the Id of the entity
         * 
         * @param id : id of the entity
         */
        void setId(const size_t id);

      private:
        std::unordered_map<std::type_index, IComponent *> _components;
        size_t _id;
    };
} // namespace ecs
#endif //__ENTITY__
