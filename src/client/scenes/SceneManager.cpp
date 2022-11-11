/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** SceneManager
*/

#include "SceneManager.hpp"
#include "Hub.hpp"

using namespace rtype;

SceneManager::SceneManager() : _scale(3), _window(sf::VideoMode(640 * _scale, 360 * _scale), "Subaquatica") {}

SceneManager::~SceneManager() { }

void SceneManager::run()
{
    sf::Event event;
    Communicator communicator;
    std::shared_ptr<Communicator> sharedCommunicator = std::make_shared<Communicator>(communicator);
    Hub hubScene(_sceneSystem, _window, event, "Hub", _scale, sharedCommunicator);
    std::shared_ptr<Hub> sharedHubScene = std::make_shared<Hub>(hubScene);
    std::string tmpStringScene = _sceneSystem.Add(sharedHubScene);
    _sceneSystem.SwitchTo(tmpStringScene);

    int id = 0;
    while (_window.isOpen()) {
        _window.clear();
        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                _window.close();
            _sceneSystem.Update();
        }
        _sceneSystem.getCurrentScene()->getCommunicator()->lockReceiveMutex();
        std::string tmp(_sceneSystem.getCurrentScene()->getCommunicator()->_receiveStream.str());
        if (!tmp.empty()) {
            std::cout << "là ";
            if (tmp.substr(0, tmp.find_first_of(' ')) == "ok") {
                _sceneSystem.getCurrentScene()->getCommunicator()->lockSendMutex();
                id = atoi(tmp.substr(tmp.find_first_of(' '), 1).c_str());
                _sceneSystem.getCurrentScene()->getCommunicator()->_sendStream.str(std::string());
                _sceneSystem.getCurrentScene()->getCommunicator()->_sendStream << "merki " << id << " ";
                _sceneSystem.getCurrentScene()->getCommunicator()->unlockSendMutex();
            } else if (tmp.substr(0, tmp.find_first_of(' ')) == "stop")
                exit(0);
            _sceneSystem.getCurrentScene()->getCommunicator()->_receiveStream.str(std::string());
        }
        _sceneSystem.getCurrentScene()->getCommunicator()->unlockReceiveMutex();
        if (id != 0)
            std::cout << "id: " << id << " ";
        _sceneSystem.Draw();
        // receive data
        _window.display();
    }
    _sceneSystem.getCurrentScene()->getThread()->join();
    _sceneSystem.getCurrentScene()->getCommunicator()->stopCommunication();

}
