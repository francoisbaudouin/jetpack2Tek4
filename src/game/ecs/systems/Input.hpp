/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Input
*/

#ifndef INPUT_HPP_
#define INPUT_HPP_

#include "../enums/event.hpp"
#include "ASystem.hpp"
#include "SFML/Graphics.hpp"

namespace ecs
{
    class Input : public ASystem {
      public:
        Input(std::unordered_map<size_t, std::shared_ptr<ecs::Entity>> &entityMap);
        ~Input();

        std::vector<RTypeEvent> getInput(sf::Event &event);

      protected:
      private:
        void bindEventType(sf::Event &event);
        void bindMouseKey(sf::Event &event);
        void bindKeyboardKey(sf::Event &event);
        void updateEvents();
        std::vector<RTypeEvent> _events;
        RTypeEvent _event;
    };
} // namespace ecs

#endif /* !INPUT_HPP_ */
