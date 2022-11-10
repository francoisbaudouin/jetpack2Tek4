/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** SceneManager
*/

#ifndef SCENEMANAGER_HPP_
#define SCENEMANAGER_HPP_

#include "SceneSystem.hpp"

namespace rtype
{
    class SceneManager {
      public:
        SceneManager();
        ~SceneManager();
        /**
         * @brief run the scene manager, where the main loop is
         *
         */
        void run();

      private:
        float _scale;
        sf::RenderWindow _window;
        SceneSystem _sceneSystem;
    };
} // namespace rtype

#endif /* !SCENEMANAGER_HPP_ */
