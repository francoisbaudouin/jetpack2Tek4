/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Communicator
*/

#include "Communicator.hpp"
#include <iostream>

#include <chrono>
#include <iostream>
#include <thread>

using namespace rtype;

Communicator::Communicator(const size_t &port) : _port(port), _isRunning(true) {}

Communicator::Communicator(const Communicator &communicator) { this->setPort(communicator.getPort()); }

size_t Communicator::getPort() const { return this->_port; }

void Communicator::setPort(const size_t &port) { this->_port = port; }

void Communicator::lockSendMutex() { this->_sendMutex.lock(); }

void Communicator::unlockSendMutex() { this->_sendMutex.unlock(); }

void Communicator::lockReceiveMutex() { this->_receiveMutex.lock(); }

void Communicator::unlockReceiveMutex() { this->_receiveMutex.unlock(); }

void Communicator::stopCommunication() { this->_isRunning = false; }

void Communicator::run()
{
    boost::asio::ip::udp::socket socket(
        this->_ioContext, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), this->_port));

    using namespace std::chrono;
    auto next = steady_clock::now();
    auto prev = next - 200ms;

    this->_sendStream << "Default ";
    while (_isRunning) {
        auto now = steady_clock::now();
        // receive
        this->lockReceiveMutex();
        this->_receiveStream.str(std::string());
        this->_receiveBuffer = {{0}};
        socket.receive_from(boost::asio::buffer(this->_receiveBuffer), this->_remoteEndpoint);
        this->_receiveStream << this->_receiveBuffer.data();
        this->unlockReceiveMutex();
        // send
        this->lockSendMutex();
        socket.send_to(boost::asio::buffer(this->_sendStream.str()), this->_remoteEndpoint);
        this->unlockSendMutex();
        prev = now;
        next += 300ms;
        std::this_thread::sleep_until(next);
    }
}

Communicator::~Communicator() {}
