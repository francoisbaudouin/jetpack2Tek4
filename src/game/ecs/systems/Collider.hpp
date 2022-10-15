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
        /**
         * @brief Construct a new Collider object
         *
         * @param manager : shared_ptr to the ecs
         */
        Collider(std::shared_ptr<Ecs> &manager);
        ~Collider();

        /**
         * @brief compare 2 entities and check if they're colliding
         *
         * @param entity1 : id of the first entity
         * @param entity2 : id of the second entity
         */
        void compareEntities(const size_t entity1, const size_t entity2);

        /**
         * @brief check all the entities after the one passed as parameter to see if they collide
         *
         * @param entity : entity to compare
         */
        void checkEntities(const std::unordered_map<size_t, std::shared_ptr<Entity>>::iterator &entity);

        /**
         * @brief run the system to check if there are entities that collide
         *
         */
        void run() override;
    };
} // namespace ecs

#endif /* !COLLIDER_HPP_ */
