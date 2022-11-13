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

#include "ecs/entity/EntityGenerator.hpp"

#include "ecs/systems/Controll.hpp"
#include "ecs/systems/Move.hpp"

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
    // auto &entityOne = this->_ecs->getEntityManager("Lobby").createEntity();
    // entityOne.addComponent<Position>(100, 100);
    // entityOne.addComponent<Type>("Player");
    // entityOne.addComponent<DrawableServerSide>("Player");

    this->_ecs->createEntityManager("GameScene");

    generateEntity(this->_ecs->getEntityManager("GameScene"), "Player");
    this->_ecs->createSystem<Controll>(this->_ecs);
    this->_ecs->createSystem<Move>(this->_ecs);
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

    std::cout << receiveMessage << std::endl;
    if (!receiveMessage.empty()) {
        header = receiveMessage.substr(0, receiveMessage.find_first_of(' '));
        if (header == "connect" && n < 4) {
            n += 1;
            this->_communicator->_receiveStream.str(std::string());
        } else if (header == "connect" && n >= 4) {
            this->_communicator->_sendStream << "reject ";
        } else if (header == "ready") {
            nbReady += 1;
            if (nbReady == n)
                context = "Launch%";
            this->_communicator->_receiveStream.str(std::string());
        } else if (receiveMessage.substr(0, 4) == "move") {
            if (receiveMessage.size() > 5)
                this->_ecs->getSystem<Controll>().run("GameScene", receiveMessage, atoi(receiveMessage.substr(receiveMessage.find_first_of('%') + 1, 1).c_str()));
        }
    }
    this->_communicator->unlockReceiveMutex();
    this->_communicator->lockSendMutex();
    this->_communicator->_sendStream.str(std::string());
    this->_communicator->_sendStream << context << n << " ";
    this->_communicator->unlockSendMutex();
}

void Server::run()
{
    while (RUNNING) {
        this->manageReceiveData();
        this->_ecs->getSystem<Move>().run("GameScene");
        std::cout << this->_ecs->getEntityManager("GameScene").getEntity(0).getComponent<Position>().getX() << " " << this->_ecs->getEntityManager("GameScene").getEntity(0).getComponent<Position>().getY() << std::endl;
    }
    _communicator->stopCommunication();
    _communicationThread->join();
}

Server::~Server() {}
