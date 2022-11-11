/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Communicator
*/

#include "Communicator.hpp"

#include "Test.hpp"

using namespace rtype;

Communicator::Communicator(const size_t &port) : _port(port)
{
    this->_sendStream.str(std::string());
    this->_sendStream << "none ";
}

Communicator::Communicator(const Communicator &communicator) { this->setPort(communicator.getPort()); }

size_t Communicator::getPort() const { return this->_port; }

void Communicator::setPort(const size_t &port) { this->_port = port; }

void Communicator::lockSendMutex() { this->_sendMutex.lock(); }

void Communicator::unlockSendMutex() { this->_sendMutex.unlock(); }

void Communicator::lockReceiveMutex() { this->_receiveMutex.lock(); }

void Communicator::unlockReceiveMutex() { this->_receiveMutex.unlock(); }

void Communicator::run()
{
    boost::asio::ip::udp::socket socket(
        this->_ioContext, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), this->_port));

    while (RUNNING) {
        //receive
        this->lockReceiveMutex();
        this->_receiveStream.str(std::string());
        this->_receiveBuffer = {{0}};
        socket.receive_from(boost::asio::buffer(this->_receiveBuffer), this->_remoteEndpoint);
        this->_receiveStream << this->_receiveBuffer.data();
        // std::cout << "receive: " << this->_receiveStream.str() << " ";
        this->unlockReceiveMutex();
        //send
        this->lockSendMutex();
        // std::cout << "send: " << this->_sendStream.str() << " ";
        socket.send_to(boost::asio::buffer(this->_sendStream.str()), this->_remoteEndpoint);
        this->_sendStream.str(std::string());
        this->unlockSendMutex();
    }
}

Communicator::~Communicator() {}
