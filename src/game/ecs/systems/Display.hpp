/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Display
*/

#ifndef DISPLAY_HPP_
#define DISPLAY_HPP_

#include <SFML/Graphics.hpp>
#include "../components/Drawable.hpp"
#include "../components/Position.hpp"
#include "ASystem.hpp"

namespace ecs
{
    class Display : public ASystem {
      public:
        /**
         * @brief Construct a display system that display SFML entities on Window
         *
         * @param entityMap reference to the game's entity map
         */
        Display(std::shared_ptr<Ecs> &manager);
        ~Display();

        /**
         * @brief run the display system
         *
         * @param window reference to the SFML game's window
         */
        void run(sf::RenderWindow &window);
    };
} // namespace ecs

#endif /* !DISPLAY_HPP_ */
