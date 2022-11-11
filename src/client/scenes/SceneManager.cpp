/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** SceneManager
*/

#include "SceneManager.hpp"
#include "Hub.hpp"
#include "Lobby.hpp"

using namespace rtype;

SceneManager::SceneManager() : _scale(3), _window(sf::VideoMode(640 * _scale, 360 * _scale), "Subaquatica")
{
    //communicator creation that will be usefull for all scenes
    Communicator communicator;
    std::shared_ptr<Communicator> sharedCommunicator = std::make_shared<Communicator>(communicator);
    boost::thread *thread = new boost::thread(boost::bind(&rtype::Communicator::connectToServer, sharedCommunicator));

    //Hub scene
    Hub hubScene(_sceneSystem, _window, _event, "Hub", _scale, sharedCommunicator, thread);
    std::shared_ptr<Hub> sharedHubScene = std::make_shared<Hub>(hubScene);
    std::string tmpStringScene = _sceneSystem.Add(sharedHubScene);
    //Lobby scene
    Lobby lobbyScene(_sceneSystem, _window, _event, "Lobby", _scale, sharedCommunicator, thread);
    std::shared_ptr<Lobby> sharedLobbyScene = std::make_shared<Lobby>(lobbyScene);
    _sceneSystem.Add(sharedLobbyScene);

    _sceneSystem.SwitchTo(tmpStringScene);

}

SceneManager::~SceneManager()
{
    //std::cout << "segfaukt finder" << std::endl;
}

void SceneManager::receiver()
{
    _sceneSystem.getCurrentScene()->getCommunicator()->lockReceiveMutex();
    std::string tmp(_sceneSystem.getCurrentScene()->getCommunicator()->_receiveStream.str());
    if (tmp.substr(0, tmp.find(' ')) == "REJECT")
        exit(84);
    if (_sceneSystem.getCurrentScene()->getName() != tmp.substr(0, tmp.find(' ')))
        _sceneSystem.SwitchTo(tmp.substr(0, tmp.find(' ')));
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
