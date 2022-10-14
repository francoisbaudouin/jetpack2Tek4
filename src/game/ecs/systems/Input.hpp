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
        /**
         * @brief Construct a new Input object
         *
         * @param entityMap reference to the game's entity map
         */
        Input(std::shared_ptr<Ecs> &manager);
        ~Input();

        /**
         * @brief get the SFML window's inputs and bind them in RTypeEvent enum
         *
         * @param event SFML window's Event
         * @return RType's events vector
         */
        std::vector<RTypeEvent> getInput(const sf::Event &event);

      protected:
      private:
        /**
         * @brief bind event type to RTypeEvent type
         *
         * @param event SFML window's Event
         */
        void bindEventType(const sf::Event &event);
        /**
         * @brief bind event MouseKey to RTypeEvent MouseKey
         *
         * @param event SFML window's Event
         */
        void bindMouseKey(const sf::Event &event);
        /**
         * @brief bind event KeyboardKey to RTypeEvent KeyboardKey
         *
         * @param event SFML window's Event
         */
        void bindKeyboardKey(const sf::Event &event);
        /**
         * @brief update the returned events vector
         *
         */
        void updateEvents();
        std::vector<RTypeEvent> _events;
        RTypeEvent _event;
    };
} // namespace ecs

#endif /* !INPUT_HPP_ */
