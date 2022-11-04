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

Client::Client(const std::string &ipAdress, const size_t &port) : _ipAdress(ipAdress), _port(port) {}

Client::Client(const Client &client)
{
    this->setIpAdress(client.getIpAdress());
    this->setPort(client.getPort());
}

std::string Client::getIpAdress() const
{
    return this->_ipAdress;
}

size_t Client::getPort() const
{
    return this->_port;
}

void Client::setIpAdress(const std::string &ipAdress)
{
    this->_ipAdress = ipAdress;
}

void Client::setPort(const size_t &port)
{
    this->_port = port;
}

void Client::connectToServer()
{
    this->_receiverEndpoint = boost::asio::ip::udp::endpoint(boost::asio::ip::address::from_string(this->_ipAdress), this->_port);
    boost::asio::ip::udp::socket socket(this->_ioContext);

    socket.open(boost::asio::ip::udp::v4());
    this->communicate(socket);
}

void Client::communicate(boost::asio::ip::udp::socket &socket)
{
    // size_t messageLength = 0;
    (void)socket;

    while (RUNNING) {
        // fonction pour envoyer des infos au serveur à mettre ici
        // messageLength = socket.receive_from(boost::asio::buffer(this->_receiveBuffer), this->_senderEndpoint);
        // fonction qui désérialise les infos reçues par le server à mettre ici
    }
}
