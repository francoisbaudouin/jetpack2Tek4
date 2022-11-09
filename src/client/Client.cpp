/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Client
*/

#include "Client.hpp"
#include "ecs/components/DrawableClientSide.hpp"
#include "ecs/components/DrawableServerSide.hpp"
#include "ecs/components/Position.hpp"
#include "ecs/systems/Display.hpp"
#include "ecs/systems/Input.hpp"

#include "Test.hpp"

using namespace rtype;

Client::Client(const std::string &ipAdress, const size_t &port) : _ipAdress(ipAdress), _port(port) {}

Client::Client(const Client &client)
{
    this->setIpAdress(client.getIpAdress());
    this->setPort(client.getPort());
}

std::string Client::getIpAdress() const { return this->_ipAdress; }

size_t Client::getPort() const { return this->_port; }

void Client::setIpAdress(const std::string &ipAdress) { this->_ipAdress = ipAdress; }

void Client::setPort(const size_t &port) { this->_port = port; }

void Client::connectToServer()
{
    this->_receiverEndpoint =
        boost::asio::ip::udp::endpoint(boost::asio::ip::address::from_string(this->_ipAdress), this->_port);
    boost::asio::ip::udp::socket socket(this->_ioContext);

    socket.open(boost::asio::ip::udp::v4());
    this->communicate(socket);
}

void Client::communicate(boost::asio::ip::udp::socket &socket)
{
    Test test;
    size_t messageLength = 0;
    std::stringstream stringStream;
    std::string tmp;

    std::cout << "yo" << std::endl;
    this->_sendBuffer = {{0}};
    while (RUNNING) {
        // fonction pour envoyer des infos au serveur à mettre ici
        socket.send_to(boost::asio::buffer(this->_sendBuffer), this->_receiverEndpoint);
        messageLength = socket.receive_from(boost::asio::buffer(this->_receiveBuffer), this->_senderEndpoint);
        // std::cout.write(this->_receiveBuffer.data(), messageLength);
        stringStream << this->_receiveBuffer.data();
        stringStream >> test;
        std::cout << "1 name: " << test.getName() << " value: " << test.getValue() << std::endl;
        stringStream >> test;
        std::cout << "2 name: " << test.getName() << " value: " << test.getValue() << std::endl;
        stringStream >> test;
        std::cout << "3 name: " << test.getName() << " value: " << test.getValue() << std::endl;
        // fonction qui désérialise les infos reçues par le server à mettre ici
    }
}
