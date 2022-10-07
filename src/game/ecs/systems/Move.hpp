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
        Move(const std::unordered_map<size_t, std::shared_ptr<ecs::Entity>> &entityMap);
        ~Move();

        void applyVelocity(std::shared_ptr<ecs::Entity> &entity);

        void run() override;

      protected:
      private:
    };
} // namespace ecs

#endif /* !MOVE_HPP_ */
