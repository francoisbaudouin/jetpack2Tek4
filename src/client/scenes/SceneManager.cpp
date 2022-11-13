/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** SceneManager
*/

#include "SceneManager.hpp"
#include "GameScene.hpp"
#include "Hub.hpp"
#include "Lobby.hpp"

using namespace rtype;

SceneManager::SceneManager() : _scale(1), _window(sf::VideoMode(640 * _scale, 360 * _scale), "Subaquatica"), _id(5)
{
    _window.setFramerateLimit(30);
    // communicator creation that will be usefull for all scenes
    Communicator communicator;
    std::shared_ptr<Communicator> sharedCommunicator = std::make_shared<Communicator>(communicator);
    boost::thread *thread = new boost::thread(boost::bind(&rtype::Communicator::connectToServer, sharedCommunicator));

    // Hub scene
    Hub hubScene(_sceneSystem, _window, _event, "Hub", _scale, sharedCommunicator, thread);
    std::shared_ptr<Hub> sharedHubScene = std::make_shared<Hub>(hubScene);
    std::string tmpStringScene = _sceneSystem.Add(sharedHubScene);
    // Lobby scene
    Lobby lobbyScene(_sceneSystem, _window, _event, "Lobby", _scale, sharedCommunicator, thread);
    std::shared_ptr<Lobby> sharedLobbyScene = std::make_shared<Lobby>(lobbyScene);
    _sceneSystem.Add(sharedLobbyScene);

    GameScene gameScene(_sceneSystem, _window, _event, "GameScene", _scale, sharedCommunicator, thread);
    std::shared_ptr<GameScene> sharedGameScene = std::make_shared<GameScene>(gameScene);
    _sceneSystem.Add(sharedGameScene);

    _sceneSystem.SwitchTo(tmpStringScene);
}

SceneManager::~SceneManager() {}

void SceneManager::receiver()
{
    _sceneSystem.getCurrentScene()->getCommunicator()->lockReceiveMutex();
    _sceneSystem.setReceivedData(_sceneSystem.getCurrentScene()->getCommunicator()->_receiveStream.str());
    if (!_sceneSystem.getReceivedData().empty() && _sceneSystem.getCurrentScene()->getName() == "Hub") {
        if (_sceneSystem.getReceivedData().substr(0, _sceneSystem.getReceivedData().find('%')) == "reject")
            exit(84);
        else {
            _id = atoi(_sceneSystem.getReceivedData().substr(_sceneSystem.getReceivedData().find('%') + 1, 1).c_str());
            _sceneSystem.SwitchTo("Lobby");
        }
    }
    if (!_sceneSystem.getReceivedData().empty() && _sceneSystem.getCurrentScene()->getName() == "Lobby") {
        if (_sceneSystem.getReceivedData().substr(0, _sceneSystem.getReceivedData().find('%')) == "Launch")
            _sceneSystem.SwitchTo("GameScene");
    }
    _sceneSystem.getCurrentScene()->getCommunicator()->unlockReceiveMutex();
}

void SceneManager::run()
{
    while (_window.isOpen()) {
        _window.clear();
        receiver();
        while (_window.pollEvent(_event)) {
            _sceneSystem.Update();
            if (_event.type == sf::Event::Closed)
                _window.close();
        }
        _sceneSystem.Draw();
        _window.display();
    }
    _sceneSystem.getCurrentScene()->getCommunicator()->stopCommunication();
    _sceneSystem.getCurrentScene()->getThread()->join();
    //}
}
