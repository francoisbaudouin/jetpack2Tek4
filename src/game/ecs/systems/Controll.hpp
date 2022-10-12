/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Controll
*/

#ifndef CONTROLL_HPP_
#define CONTROLL_HPP_
#include "ASystem.hpp"
#include "../components/Controllable.hpp"
#include "../components/Position.hpp"
#include "../components/Velocity.hpp"
#include "../enums/controlls.hpp"
#include <vector>


namespace ecs
{
    class Controll : public ASystem {
      public:
        Controll(std::unordered_map<size_t, std::shared_ptr<ecs::Entity>> &entityMap);
        ~Controll();

      void run(std::vector<RTypeEvent> controll);

      protected:
      private:
    };
} // namespace ecs

#endif /* !CONTROLL_HPP_ */
