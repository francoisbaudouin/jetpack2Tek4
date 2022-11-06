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
    class Ecs;

    class Move : public ASystem {
      public:
        /**
         * @brief Construct a new Move system
         *
         * @param manager : list of all the entity
         */
        Move(std::shared_ptr<Ecs> &manager);
        ~Move();

        /**
         * @brief move one entity from it's position and velocity
         *
         * @param entity : entity to move
         */
        void applyVelocity(Entity &entity);

        /**
         * @brief check all entity if they can move then call 'move()' on the ones that can
         *
         * @param sceneId : id of the scene to select the entityManager related
         */
        void run(const std::string &sceneName) override;

      protected:
      private:
    };
} // namespace ecs

#endif /* !MOVE_HPP_ */
