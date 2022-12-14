/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Type
*/

#ifndef TYPE_HPP_
#define TYPE_HPP_

#include "../enums/entityTypes.hpp"
#include "AComponent.hpp"

namespace ecs
{
    class Type : public AComponent {
      public:
        /**
         * @brief contruct a type component, that identify the type of an entity
         *
         * @param type entityType to set
         */
        Type(const size_t entityId, const std::string type);
        ~Type();
        /**
         * @brief Get the Entity Type property
         *
         * @return defined entity type
         */
        std::string getEntityType() const;

      protected:
      private:
        std::string _type;
    };
} // namespace ecs

#endif /* !TYPE_HPP_ */
