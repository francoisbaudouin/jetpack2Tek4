/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Collider
*/

#ifndef COLLIDER_HPP_
#define COLLIDER_HPP_

#include "ASystem.hpp"

namespace ecs
{
    class Collider : public ASystem {
      public:
        Collider(std::shared_ptr<Ecs> &manager);
        ~Collider();

        void compareEntities(const size_t entity1, const size_t entity2);

        void checkEntities(const std::unordered_map<size_t, std::shared_ptr<Entity>>::iterator &entity);

        void run() override;

      protected:
      private:
    };
} // namespace ecs

#endif /* !COLLIDER_HPP_ */
