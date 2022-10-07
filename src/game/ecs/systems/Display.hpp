/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Display
*/

#ifndef DISPLAY_HPP_
#define DISPLAY_HPP_

#include "ASystem.hpp"
#include <SFML/Graphics.hpp>

namespace ecs
{
    class Display : public ASystem {
      public:
        Display(std::unordered_map<size_t, std::shared_ptr<ecs::Entity>> &entityMap);
        ~Display();

        void run(sf::RenderWindow &window);
    };
} // namespace ecs

#endif /* !DISPLAY_HPP_ */
