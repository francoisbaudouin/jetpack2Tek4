/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Input
*/

#ifndef INPUT_HPP_
#define INPUT_HPP_

#include "../enums/Event.hpp"
#include "ASystem.hpp"
#include "SFML/Graphics.hpp"

namespace ecs
{
    class Input : public ASystem {
      public:
        Input(std::unordered_map<size_t, std::shared_ptr<ecs::Entity>> &entityMap);
        ~Input();

        RTypeEvent getInput(sf::RenderWindow &window);

      protected:
      private:
        RTypeEvent _event;
    };
} // namespace ecs

#endif /* !INPUT_HPP_ */
