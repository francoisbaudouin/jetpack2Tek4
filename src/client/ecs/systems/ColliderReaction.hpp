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
#include "../components/Velocity.hpp"
#include "../enums/entityTypes.hpp"
#include "ASystem.hpp"

namespace ecs
{
    class ColliderReaction : public ASystem {
      public:
        /**
         * @brief Construct a new Collider Reaction that react to Collides events
         *
         * @param manager shared pointer to ecs
         */
        ColliderReaction(std::shared_ptr<Ecs> manager);
        ~ColliderReaction();
        /**
         * @brief run the ControllerReaction system that will react depending on entityType of entities given in
         * parameters
         *
         * @param entityId1 id of the first entity
         * @param entityId2 id of the second entity
         */
        void run(const size_t entityId1, const size_t entityId2);

      private:
        std::map<std::pair<entityType, entityType>,
            void (*)(std::shared_ptr<Ecs> &manager, Entity &entity1, Entity &entity2)>
            _reactionMap;
    };
} // namespace ecs

#endif /* !COLLIDERREACTION_HPP_ */
