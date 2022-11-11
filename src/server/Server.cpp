/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Server
*/
#define RUNNING 1

#include <iostream>

#include "Server.hpp"

using namespace rtype;

Server::Server(std::shared_ptr<Communicator> communicator, std::shared_ptr<ecs::Ecs> ecs)
    : _communicator(communicator), _ecs(ecs)
{
}

void Server::manageReceiveData()
{
    std::string receiveMessage(this->_communicator->_receiveStream.str());
    std::string header;
    static int n = 0;

    // std::cout << receiveMessage << std::endl;
    if (!receiveMessage.empty()) {
        header = receiveMessage.substr(0, receiveMessage.find_first_of(' '));
        // std::cout << header << std::endl;
        // std::cout << "nbClient: " << n << std::endl;
        if (header == "connect" && n < 4) {
            this->_communicator->lockSendMutex();
            std::cout << "ici ";
            n += 1;
            this->_communicator->_sendStream.str(std::string());
            this->_communicator->_sendStream << "ok " << n << " ";
            this->_communicator->unlockSendMutex();
        } else if (header == "connect" && n >= 4) {
            this->_communicator->lockSendMutex();
            this->_communicator->_sendStream.str(std::string());
            this->_communicator->_sendStream << "stop ";
            this->_communicator->unlockSendMutex();
        } else if (header == "merki")
            std::cout << "id: " << receiveMessage.substr(receiveMessage.find_first_of(' '), 1) << std::endl;
        // std::cout << "connecté" << std::endl;
    }
}

void Server::run()
{
    this->_ecs->createEntityManager("Lobby");

    while (RUNNING) {
        // this->_communicator->lockSendMutex();
        // this->_communicator->_sendStream.str(std::string());
        // this->_communicator->_sendStream << test << " " << test1 << " " << test2 << " ";
        // this->_communicator->unlockSendMutex();
        this->_communicator->lockReceiveMutex();
        this->manageReceiveData();
        this->_communicator->_receiveStream.str(std::string());
        this->_communicator->unlockReceiveMutex();
    }
}

Server::~Server() {}
