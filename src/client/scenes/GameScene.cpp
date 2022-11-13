/*
** EPITECH PROJECT, 2022
** RTypeMirror
** File description:
** GameScene
*/

#include "GameScene.hpp"

// #include "../ecs/enums/event.hpp"

#include "../ecs/systems/Input.hpp"
#include "../ecs/systems/Fire.hpp"

using namespace rtype;
using namespace ecs;

GameScene::GameScene(std::shared_ptr<SceneSystem> sceneSystem, sf::RenderWindow &window, sf::Event &event,
    const std::string &sceneName, const float scale, std::shared_ptr<Communicator> communicator, boost::thread *thread)
    : AScene(sceneSystem, window, sceneName, scale, communicator, thread), _event(event)
{
}

GameScene::~GameScene() {}

void GameScene::OnCreate() { _sceneSystem->getEcs()->createEntityManager(this->getName()); }

void GameScene::OnDestroy() {}

void GameScene::OnActivate() { _sceneSystem->getTextureDatabase()->onCall(this->getName()); }

void GameScene::OnDeactivate() {}

void GameScene::ProcessInput() {}

void GameScene::Update()
{
    _communicator->lockSendMutex();
    _communicator->_sendStream.str(std::string());
    _communicator->_sendStream << "move%";
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        _communicator->_sendStream << this->_id << "_up ";
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        _communicator->_sendStream << this->_id << "_left ";
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        _communicator->_sendStream << this->_id << "_down ";
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        _communicator->_sendStream << this->_id << "_right ";
    _communicator->unlockSendMutex();

    return;
}

void GameScene::Draw() {}
