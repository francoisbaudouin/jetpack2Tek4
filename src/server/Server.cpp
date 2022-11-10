/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Server
*/

#include "Server.hpp"

#include "Test.hpp"

using namespace rtype;

Server::Server(const size_t &port) : _port(port) {}

Server::Server(const Server &server) { this->setPort(server.getPort()); }

size_t Server::getPort() const { return this->_port; }

void Server::setPort(const size_t &port) { this->_port = port; }

void Server::lockSendMutex() { this->_sendMutex.lock(); }

void Server::unlockSendMutex() { this->_sendMutex.unlock(); }

void Server::lockReceiveMutex() { this->_receiveMutex.lock(); }

void Server::unlockReceiveMutex() { this->_receiveMutex.unlock(); }

void Server::run()
{
    boost::asio::ip::udp::socket socket(
        this->_ioContext, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), this->_port));

    this->_sendStream << "NONE ";
    while (RUNNING) {
        this->lockReceiveMutex();
        this->_receiveStream.str(std::string());
        this->_receiveBuffer = {{0}};
        socket.receive_from(boost::asio::buffer(this->_receiveBuffer), this->_remoteEndpoint);
        this->_receiveStream << this->_receiveBuffer.data();
        this->unlockReceiveMutex();
        this->lockSendMutex();
        socket.send_to(boost::asio::buffer(this->_sendStream.str()), this->_remoteEndpoint);
        this->unlockSendMutex();
    }
}

Server::~Server() {}
