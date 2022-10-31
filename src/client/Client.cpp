/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Client
*/

#include <string>
#include "Client.hpp"
#include "ecs/systems/Display.hpp"
#include "ecs/systems/Input.hpp"

using namespace rtype;

Client::Client(const std::string &ipAdress, const size_t &port) : _window(sf::VideoMode(800, 600), "Client window")
{
    ecs::Ecs ecs;
    this->_sharedEcs = std::make_shared<ecs::Ecs>(ecs);
    _sharedEcs->addSystem<ecs::Input>(_sharedEcs);
    _sharedEcs->addSystem<ecs::Display>(_sharedEcs);

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
    (void)socket;
    // size_t messageLength = 0;

    while (_window.isOpen()) {
        // fonction pour envoyer des infos au serveur à mettre ici
        // messageLength = socket.receive_from(boost::asio::buffer(this->_receiveBuffer), this->_senderEndpoint);
        // fonction qui désérialise les infos reçues par le server à mettre ici
        // update ecs côté client
        _window.clear();
        while (_window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                _window.close();
        _sharedEcs->getSystem<ecs::Display>().run(_window);
        _window.display();
    }
}
