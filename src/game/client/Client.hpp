/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Client
*/

#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#include <SFML/Graphics.hpp>
#include "../ecs/Ecs.hpp"

namespace ecs
{
    class Client {
      public:
        Client();

        ~Client();

        // member function
        void run();

      protected:
      private:
        sf::Texture _tmpTexture;
        sf::Texture _tmpTexture2;

        std::shared_ptr<Ecs> _manager;
        sf::RenderWindow _window;
    };
} // namespace ecs

#endif /* !CLIENT_HPP_ */