/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Communicator
*/
#include "Communicator.hpp"
#include "ecs/components/DrawableClientSide.hpp"
#include "ecs/components/DrawableServerSide.hpp"
#include "ecs/components/Position.hpp"
#include "ecs/systems/Display.hpp"
#include "ecs/systems/Input.hpp"

#include "Test.hpp"

using namespace rtype;

Communicator::Communicator(const std::string &ipAdress, const size_t &port) : _ipAdress(ipAdress), _port(port) {}

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
    this->communicate(socket);
}

void Communicator::communicate(boost::asio::ip::udp::socket &socket)
{
    Test test;
    std::stringstream stringStream;

    this->_sendStream.str(std::string());
    this->_sendStream << "STOP ";
    while (RUNNING) {
        this->lockSendMutex();
        socket.send_to(boost::asio::buffer(this->_sendStream.str()), this->_receiverEndpoint);
        this->unlockSendMutex();
        this->lockReceiveMutex();
        this->_receiveStream.str(std::string());
        boost::array<char, 128> receiveBuffer = {{0}};
        socket.receive_from(boost::asio::buffer(receiveBuffer), this->_senderEndpoint);
        stringStream << receiveBuffer.data();
        stringStream >> test;
        std::cout << "1 name: " << test.getName() << " value: " << test.getValue() << std::endl;
        stringStream >> test;
        std::cout << "2 name: " << test.getName() << " value: " << test.getValue() << std::endl;
        stringStream >> test;
        std::cout << "3 name: " << test.getName() << " value: " << test.getValue() << std::endl;
        this->unlockReceiveMutex();
    }
}

void Communicator::lockSendMutex() { this->_sendMutex.lock(); }

void Communicator::unlockSendMutex() { this->_sendMutex.unlock(); }

void Communicator::lockReceiveMutex() { this->_sendMutex.lock(); }

void Communicator::unlockReceiveMutex() { this->_sendMutex.unlock(); }
