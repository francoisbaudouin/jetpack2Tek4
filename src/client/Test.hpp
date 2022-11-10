/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Test
*/

#ifndef TEST_HPP_
#define TEST_HPP_

#include "assetsManager/TextureDatabase.hpp"

#include "ecs/Ecs.hpp"
#include "ecs/entity/EntityGenerator.hpp"

namespace rtype
{
    class Test {
      public:
        Test();
        ~Test();

        void run();

      protected:
      private:
        sf::RenderWindow _window;
        std::shared_ptr<ecs::Ecs> _manager;
        std::shared_ptr<TextureDatabase> _textures;
    };
} // namespace rtype

#endif /* !TEST_HPP_ */
