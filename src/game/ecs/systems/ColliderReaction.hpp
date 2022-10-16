/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** ColliderReaction
*/

#ifndef COLLIDERREACTION_HPP_
#define COLLIDERREACTION_HPP_

#include <map>
#include "../components/Position.hpp"
#include "../components/Type.hpp"
#include "../enums/entityTypes.hpp"
#include "ASystem.hpp"
#include <functional>

namespace ecs
{
    class ColliderReaction : public ASystem {
      public:
        ColliderReaction(std::shared_ptr<Ecs> manager);
        ~ColliderReaction();



        void run(const size_t entityId1, const size_t entityId2);

      protected:
      private:
        std::map<std::pair<entityType, entityType>, void (*) (std::shared_ptr<Ecs> &manager, Entity &entity1, Entity &entity2)>
        _reactionMap;
    };
} // namespace ecs

#endif /* !COLLIDERREACTION_HPP_ */
