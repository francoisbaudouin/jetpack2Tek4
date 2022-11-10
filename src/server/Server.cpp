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

void Server::lockMutex() { this->_mutex.lock(); }

void Server::unlockMutex() { this->_mutex.unlock(); }

void Server::run()
{
    boost::asio::ip::udp::socket socket(
        this->_ioContext, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), this->_port));
    Test test;
    Test test1("Mattéo", 2);
    Test test2("Timothé", 1);
    std::string tmp;

    this->_sendStream << test << " " << test1 << " " << test2 << " ";
    this->_receiveStream.clear();
    while (RUNNING) {
        this->lockMutex();
        socket.receive_from(boost::asio::buffer(this->_receiveBuffer), this->_remoteEndpoint);
        this->_receiveStream << this->_receiveBuffer.data();
        this->_receiveStream >> tmp;
        std::cout << tmp << std::endl;
        this->unlockMutex();

        this->lockMutex();
        socket.send_to(boost::asio::buffer(this->_sendStream.str()), this->_remoteEndpoint);
        this->unlockMutex();
    }
}

Server::~Server() {}
