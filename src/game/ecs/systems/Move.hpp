/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Move
*/

#ifndef MOVE_HPP_
#define MOVE_HPP_

#include "ASystem.hpp"

namespace ecs
{
    class Move : public ASystem {
      public:
        /**
         * @brief Construct a new Move system
         *
         * @param entityMap : list of all the entity
         */
        Move(std::unordered_map<size_t, std::shared_ptr<ecs::Entity>> &entityMap);
        /**
         * @brief Destroy the Move object
         *
         */
        ~Move();

        /**
         * @brief move one entity from it's position and velocity
         *
         * @param entity : entity to move
         */
        void applyVelocity(std::shared_ptr<ecs::Entity> &entity);

        /**
         * @brief check all entity if they can move then call 'move()' on the ones that can
         *
         */
        void run() override;

      protected:
      private:
    };
} // namespace ecs

#endif /* !MOVE_HPP_ */
