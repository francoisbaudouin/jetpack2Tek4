/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** WriteInBox
*/

#ifndef WRITEINBOX_HPP_
#define WRITEINBOX_HPP_

#include "ASystem.hpp"
#include "SFML/Graphics.hpp"

namespace ecs
{
    class Ecs;
    class WriteInBox : public ASystem {
      public:
        WriteInBox(std::shared_ptr<Ecs> &manager);
        ~WriteInBox();

        void run(const std::string &sceneName, const sf::Event &event, sf::RenderWindow &window);
      private:
        std::string stringToAppend;
    };
} // namespace ecs

#endif /* !WRITEINBOX_HPP_ */
