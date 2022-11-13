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
#include "ecs/components/Velocity.hpp"
#include "ecs/components/Type.hpp"

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
    this->_ecs->createEntityManager("GameScene");
    this->_ecs->createSystem<Move>(this->_ecs);

    auto &enemy = this->_ecs->getEntityManager("GameScene").createEntity();
    enemy.addComponent<Position>(0, 0);
    enemy.addComponent<Type>("Enemy");
    enemy.addComponent<DrawableServerSide>("Enemy");
    enemy.addComponent<Velocity>(0.001, 0);

}

std::string Server::fillSendStream()
{
    std::string fillString = " ";

    for (auto &entity : this->_ecs->getEntityManager("GameScene").getEntities()) {
        fillString += std::to_string(entity.second->getId()) + "_";
        if (entity.second->hasComponent<DrawableServerSide>()) {
            fillString += entity.second->getComponent<DrawableServerSide>().getTextureType() + ":";
        }
        if (entity.second->hasComponent<Position>()) {
            fillString += std::to_string(entity.second->getComponent<Position>().getX()) + ","
                + std::to_string(entity.second->getComponent<Position>().getY()) + " ";
        }
    }
    return fillString;
}

void Server::manageReceiveData()
{
    this->_communicator->lockReceiveMutex();
    std::string receiveMessage(this->_communicator->_receiveStream.str());
    std::string header;
    static std::string context = "context%";
    static int n = 0;
    static int nbReady = 0;

    if (!receiveMessage.empty()) {
        header = receiveMessage.substr(0, receiveMessage.find_first_of(' '));
        if (header == "connect" && n < 4) {
            auto &player = this->_ecs->getEntityManager("GameScene").createEntity();
            player.addComponent<Position>(0, 0);
            player.addComponent<Type>("Player");
            player.addComponent<DrawableServerSide>("Player");
            n += 1;
            this->_communicator->_receiveStream.str(std::string());
        } else if (header == "connect" && n >= 4) {
            this->_communicator->_sendStream << "reject ";
        } else if (header == "ready") {
            nbReady += 1;
            if (nbReady == n) {
                context = "Launch%";
            }
            this->_communicator->_receiveStream.str(std::string());
        }
    }
    this->_communicator->unlockReceiveMutex();
    this->_communicator->lockSendMutex();
    this->_communicator->_sendStream.str(std::string());
    this->_communicator->_sendStream << context << n << fillSendStream();
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
        _ecs->getSystem<Move>().run("GameScene");
        // this->_communicator->_receiveStream.str(std::string());
    }
    _communicator->stopCommunication();
    _communicationThread->join();
}

Server::~Server() {}