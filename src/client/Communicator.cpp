/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Communicator
*/
#include "Communicator.hpp"
#include "Test.hpp"

using namespace rtype;

Communicator::Communicator(const std::string &ipAdress, const size_t &port)
    : _ipAdress(ipAdress), _port(port), _isRunning(true)
{
}

Communicator::Communicator(const Communicator &communicator)
{
    this->setIpAdress(communicator.getIpAdress());
    this->setPort(communicator.getPort());
}

std::string Communicator::getIpAdress() const { return this->_ipAdress; }

size_t Communicator::getPort() const { return this->_port; }

void Communicator::setIpAdress(const std::string &ipAdress) { this->_ipAdress = ipAdress; }

void Communicator::setPort(const size_t &port) { this->_port = port; }

void Communicator::connectToServer()
{
    this->_receiverEndpoint =
        boost::asio::ip::udp::endpoint(boost::asio::ip::address::from_string(this->_ipAdress), this->_port);
    boost::asio::ip::udp::socket socket(this->_ioContext);

    socket.open(boost::asio::ip::udp::v4());
    _isRunning = true;
    this->communicate(socket);
}

void Communicator::stopCommunication() { _isRunning = false; }

void Communicator::communicate(boost::asio::ip::udp::socket &socket)
{
    Test test;

    this->_sendStream.str(std::string());
    this->_sendStream << "connect ";
    while (_isRunning) {
        // send
        this->lockSendMutex();
        socket.send_to(boost::asio::buffer(this->_sendStream.str()), this->_receiverEndpoint);
        this->_sendStream.str(std::string());
        this->unlockSendMutex();
        // receive
        this->lockReceiveMutex();
        this->_receiveStream.str(std::string());
        boost::array<char, 128> receiveBuffer = {{0}};
        socket.receive_from(boost::asio::buffer(receiveBuffer), this->_senderEndpoint);
        this->_receiveStream << receiveBuffer.data();
        this->unlockReceiveMutex();
    }
}

void Communicator::lockSendMutex() { this->_sendMutex.lock(); }

void Communicator::unlockSendMutex() { this->_sendMutex.unlock(); }

void Communicator::lockReceiveMutex() { this->_sendMutex.lock(); }

void Communicator::unlockReceiveMutex() { this->_sendMutex.unlock(); }
