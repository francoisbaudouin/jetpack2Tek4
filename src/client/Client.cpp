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

Client::Client()
{
    this->_value = 2;
}

Client::Client(const Client &client)
{
    this->_receiverEndpoint = client._receiverEndpoint;
}

void Client::connectToServer(const std::string &ipAdress, const size_t &port)
{
    this->_receiverEndpoint = boost::asio::ip::udp::endpoint(boost::asio::ip::address::from_string(ipAdress), port);
    boost::asio::ip::udp::socket socket(this->_ioContext);

    socket.open(boost::asio::ip::udp::v4());
    this->communicate(socket);
}

void Client::communicate(boost::asio::ip::udp::socket &socket)
{
    size_t messageLength = 0;

    while (RUNNING) {
        // fonction pour envoyer des infos au serveur à mettre ici
        // messageLength = socket.receive_from(boost::asio::buffer(this->_receiveBuffer), this->_senderEndpoint);
        // fonction qui désérialise les infos reçues par le server à mettre ici
        // update ecs côté client
    }
}
