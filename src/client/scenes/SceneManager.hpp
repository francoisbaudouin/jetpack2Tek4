/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** SceneManager
*/

#ifndef SCENEMANAGER_HPP_
#define SCENEMANAGER_HPP_

#include <SFML/Audio.hpp>
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

        void receiver();

      private:
        sf::Music _music;
        std::shared_ptr<SceneSystem> _sceneSystem;
        float _scale;
        sf::RenderWindow _window;
        sf::Event _event;
        size_t _id;
    };
} // namespace rtype

#endif /* !SCENEMANAGER_HPP_ */
