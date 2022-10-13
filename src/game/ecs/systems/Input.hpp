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
        Input(std::unordered_map<size_t, std::shared_ptr<ecs::Entity>> &entityMap);
        ~Input();

        /**
         * @brief get the SFML window's inputs and bind them in RTypeEvent enum
         *
         * @param event SFML window's Event
         * @return RType's events vector
         */
        std::vector<RTypeEvent> getInput(sf::Event &event);

      protected:
      private:
        /**
         * @brief bind event type to RTypeEvent type
         *
         * @param event SFML window's Event
         */
        void bindEventType(sf::Event &event);
        /**
         * @brief bind event MouseKey to RTypeEvent MouseKey
         *
         * @param event SFML window's Event
         */
        void bindMouseKey(sf::Event &event);
        /**
         * @brief bind event KeyboardKey to RTypeEvent KeyboardKey
         *
         * @param event SFML window's Event
         */
        void bindKeyboardKey(sf::Event &event);
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
