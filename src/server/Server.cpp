/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Server
*/
#define RUNNING 1

#include <iostream>

#include "Server.hpp"

#include "ecs/components/DrawableServerSide.hpp"
#include "ecs/components/Position.hpp"
#include "ecs/components/Type.hpp"

using namespace rtype;
using namespace ecs;

Server::Server()
{
    rtype::Communicator communicator;
    _communicator = std::make_shared<rtype::Communicator>(communicator);
    _communicationThread = new boost::thread(boost::bind(&rtype::Communicator::run, _communicator));
    Ecs ecs;
    _ecs = std::make_shared<Ecs>(ecs);

    // entity generation

    this->_ecs->createEntityManager("Lobby");
    auto &entityOne = this->_ecs->getEntityManager("Lobby").createEntity();
    entityOne.addComponent<Position>(100, 100);
    entityOne.addComponent<Type>("Player");
    entityOne.addComponent<DrawableServerSide>("Player");
}

void Server::manageReceiveData()
{
    // this->_communicator->lockSendMutex();
    this->_communicator->lockReceiveMutex();
    std::string receiveMessage(this->_communicator->_receiveStream.str());
    std::string header;
    static std::string context = "context%";
    static int n = 0;
    static int nbReady = 0;

    if (!receiveMessage.empty()) {
        header = receiveMessage.substr(0, receiveMessage.find_first_of(' '));
        if (header == "connect" && n < 4) {
            n += 1;
            this->_communicator->_receiveStream.str(std::string());
        } else if (header == "connect" && n >= 4) {
            // this->_communicator->lockSendMutex();
            // this->_communicator->_sendStream.str(std::string());
            // this->_communicator->_sendStream << "REJECT ";
            // this->_communicator->unlockSendMutex();
        } else if (header == "ready") {
            nbReady+=1;
            if (nbReady == n)
                context = "Launch%";
            this->_communicator->_receiveStream.str(std::string());
        }
    }
    this->_communicator->unlockReceiveMutex();
    this->_communicator->lockSendMutex();
    this->_communicator->_sendStream.str(std::string());
    this->_communicator->_sendStream << context << n << " 0_Player:100,100 1_Enemy:25,25 ";
    this->_communicator->unlockSendMutex();
}

void Server::manageSendData()
{
    // this->_communicator->lockSendMutex();
    // this->_communicator->unlockSendMutex();
}

void Server::run()
{
    while (RUNNING) {
        // this->_communicator->lockSendMutex();
        // this->_communicator->_sendStream.str(std::string());
        // this->_communicator->_sendStream << test << " " << test1 << " " << test2 << " ";
        // this->_communicator->unlockSendMutex();
        this->manageReceiveData();
        this->manageSendData();
        // this->_communicator->_receiveStream.str(std::string());
    }
    _communicator->stopCommunication();
    _communicationThread->join();
}

Server::~Server() {}