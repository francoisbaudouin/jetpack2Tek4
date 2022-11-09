/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** SceneManager
*/

#include "SceneManager.hpp"

using namespace rtype;

SceneManager::SceneManager() : _window(sf::VideoMode(640, 360), "Subaquatica") {}

SceneManager::~SceneManager() {}

void SceneManager::run()
{
    sf::Event event;
    // size_t messageLength = 0;

    while (_window.isOpen()) {
        // fonction pour envoyer des infos au serveur à mettre ici
        // fonction qui désérialise les infos reçues par le server à mettre ici
        // update ecs côté client
        _window.clear();
        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                _window.close();
        }
        _sceneSystem.Update();
        _window.display();
    }
}
