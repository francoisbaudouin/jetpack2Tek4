/*
** EPITECH PROJECT, 2022
** RTypeMirror
** File description:
** AScene
*/

#include "AScene.hpp"

using namespace rtype;

AScene::AScene(std::shared_ptr<SceneSystem> sceneSystem, sf::RenderWindow &window, const std::string &sceneName,
    const float scale, std::shared_ptr<Communicator> communicator, boost::thread *thread)
    : _sceneSystem(sceneSystem), _window(window), _sceneName(sceneName), _scale(scale), _communicator(communicator),
      _thread(thread)
{
}

std::string AScene::getName() const { return _sceneName; }

boost::thread *AScene::getThread() { return _thread; }

std::shared_ptr<Communicator> AScene::getCommunicator() { return _communicator; }

size_t AScene::getId() const { return this->_id; }

void AScene::setId(const size_t &id) { this->_id = id; }
