/*
** EPITECH PROJECT, 2022
** RTypeMirror
** File description:
** AScene
*/

#include "AScene.hpp"

using namespace rtype;

AScene::AScene(SceneSystem &sceneSystem, sf::RenderWindow &window, const std::string &sceneName)
    : _sceneSystem(sceneSystem), _window(window), _sceneName(sceneName)
{
}

std::string AScene::getName() const { return _sceneName; }
