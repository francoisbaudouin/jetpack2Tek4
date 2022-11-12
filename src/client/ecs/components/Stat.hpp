/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Stat
*/

#ifndef STAT_HPP_
#define STAT_HPP_

#include "AComponent.hpp"

namespace ecs
{
    class Stat : public AComponent {
      public:
        Stat(const size_t entityId, const size_t health = 1);
        ~Stat();

        size_t getHealth() const;
        void setHealth(const size_t health);

      private:
        size_t _health;
    };
} // namespace ecs

#endif /* !STAT_HPP_ */
