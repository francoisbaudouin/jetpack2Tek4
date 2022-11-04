/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Client
*/

#include "Client.hpp"
#include "ecs/systems/Display.hpp"
#include "ecs/systems/Input.hpp"

using namespace rtype;

Client::Client(const std::string &ipAdress, const size_t &port) : _window(sf::VideoMode(640, 360), "Client window")
{
    this->_receiverEndpoint = boost::asio::ip::udp::endpoint(boost::asio::ip::address::from_string(ipAdress), port);
}

void Client::connectToServer()
{
    boost::asio::ip::udp::socket socket(this->_ioContext);

    socket.open(boost::asio::ip::udp::v4());
    this->run(socket);
}

void Client::run(boost::asio::ip::udp::socket &socket)
{
    sf::Event event;
    size_t messageLength = 0;
    MainMenu tmpMainMenu(_sceneSystem, _window);
    std::shared_ptr<MainMenu> mainMenu = std::make_shared<MainMenu>(tmpMainMenu);
    unsigned int mainMenuID = _sceneSystem.Add(mainMenu);
    _sceneSystem.SwitchTo(mainMenuID);

    while (_window.isOpen()) {
        // fonction pour envoyer des infos au serveur à mettre ici
        // fonction qui désérialise les infos reçues par le server à mettre ici
        // update ecs côté client
        _window.clear();
        while (_window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                _window.close();
        _sceneSystem.Update();
        _window.display();
    }
}
