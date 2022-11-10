/*
** EPITECH PROJECT, 2022
** RTypeMirror
** File description:
** AScene
*/

#include "AScene.hpp"

using namespace rtype;

AScene::AScene(SceneSystem &sceneSystem, sf::RenderWindow &window, const std::string &sceneName, const float scale,
    std::shared_ptr<Communicator> communicator)
    : _sceneSystem(sceneSystem), _window(window), _sceneName(sceneName), _scale(scale), _communicator(communicator)
{
}

std::string AScene::getName() const { return _sceneName; }

std::shared_ptr<boost::thread> AScene::getThread() { return _thread; }

std::shared_ptr<Communicator> AScene::getCommunicator() { return _communicator; }
