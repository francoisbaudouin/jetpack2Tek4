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
#include "ecs/components/Velocity.hpp"

#include "ecs/entity/EntityGenerator.hpp"

#include "ecs/systems/Controll.hpp"
#include "ecs/systems/Fire.hpp"
#include "ecs/systems/Move.hpp"

using namespace rtype;
using namespace ecs;

Server::Server()
{
    _sceneName = "Hub";
    rtype::Communicator communicator;
    _communicator = std::make_shared<rtype::Communicator>(communicator);
    _communicationThread = new boost::thread(boost::bind(&rtype::Communicator::run, _communicator));
    Ecs ecs;
    _ecs = std::make_shared<Ecs>(ecs);

    // entity generation

    this->_ecs->createEntityManager("Hub");
    this->_ecs->createEntityManager("Lobby");
    this->_ecs->createEntityManager("GameScene");
    this->_ecs->createSystem<Move>(this->_ecs);
    this->_ecs->createSystem<Controll>(this->_ecs);

    auto &Player = this->_ecs->getEntityManager("GameScene")
                       .getEntity(generateEntity(this->_ecs->getEntityManager("GameScene"), "Player"));
    Player.addComponent<DrawableServerSide>("Player");
    this->_ecs->createSystem<Fire>(this->_ecs);
}

std::string Server::fillSendStream()
{
    std::string fillString = " ";

    for (auto &entity : this->_ecs->getEntityManager(_sceneName).getEntities()) {
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
            _sceneName = "Lobby";
            auto &player = this->_ecs->getEntityManager("Lobby").getEntity(
                generateEntity(this->_ecs->getEntityManager("Lobby"), "Player"));
            player.addComponent<DrawableServerSide>("Player");
            player.getComponent<Position>().setPosition(40, n * 48 + 50);
            n += 1;
            this->_communicator->_receiveStream.str(std::string());
        } else if (header == "connect" && n >= 4) {
            this->_communicator->_sendStream << "reject ";
        } else if (header == "ready") {
            nbReady += 1;
            if (nbReady == n) {
                context = "Launch%";
                _sceneName = "GameScene";
            }
            this->_communicator->_receiveStream.str(std::string());
        } else if (header == "notready") {
            nbReady -= 1;
            this->_communicator->_receiveStream.str(std::string());
        } else if (receiveMessage.substr(0, receiveMessage.find_first_of('%')) == "action") {
            this->_ecs->getSystem<Controll>().run("GameScene",
                receiveMessage.substr(receiveMessage.find_first_of('_') + 1),
                atoi(receiveMessage.substr(receiveMessage.find_first_of('%') + 1, 1).c_str()));
        }
    }
    this->_communicator->unlockReceiveMutex();
    this->_communicator->lockSendMutex();
    this->_communicator->_sendStream.str(std::string());
    this->_communicator->_sendStream << context << n << fillSendStream();
    this->_communicator->unlockSendMutex();
}

void Server::run()
{
    while (RUNNING) {
        this->manageReceiveData();
        this->_ecs->getSystem<Move>().run("GameScene");
    }
    _communicator->stopCommunication();
    _communicationThread->join();
}

Server::~Server() {}
