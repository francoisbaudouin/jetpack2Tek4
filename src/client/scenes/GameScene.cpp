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

GameScene::GameScene(SceneSystem &sceneSystem, sf::RenderWindow &window, sf::Event &event, const std::string &sceneName,
    const float scale, std::shared_ptr<Communicator> communicator, boost::thread *thread)
    : AScene(sceneSystem, window, sceneName, scale, communicator, thread), _event(event)
{
}

GameScene::~GameScene() {}

void GameScene::OnCreate() { _sceneSystem.getEcs()->createEntityManager(this->getName()); }

void GameScene::OnDestroy() {}

void GameScene::OnActivate() { _sceneSystem.getTextureDatabase()->onCall(this->getName()); }

void GameScene::OnDeactivate() {}

void GameScene::ProcessInput() {}

void GameScene::Update()
{
    std::cout << _sceneSystem.getEcs()->getSystem<Input>().getInput(_event).size() << " ";
    // std::vector<RTypeEvent> rTypeEvent(_sceneSystem.getEcs()->getSystem<Input>().getInput(_event));

    // _communicator->lockSendMutex();
    // for (auto iterator : rTypeEvent) {
    //     std::cout << "ici ";
    //     if (iterator.keyboardKey == Device::KeyBoardKey::Z) {
    //         _communicator->_sendStream << this->_id << " up ";
    //     } else if (iterator.keyboardKey == Device::KeyBoardKey::Q) {
    //         _communicator->_sendStream << this->_id << " left ";
    //     } else if (iterator.keyboardKey == Device::KeyBoardKey::S) {
    //         _communicator->_sendStream << this->_id << " down ";
    //     } else if (iterator.keyboardKey == Device::KeyBoardKey::D) {
    //         _communicator->_sendStream << this->_id << " right ";
    //     }
    // }
    // _communicator->unlockSendMutex();
    return;
}

void GameScene::Draw() {}
