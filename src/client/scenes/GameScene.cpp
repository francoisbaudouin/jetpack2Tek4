/*
** EPITECH PROJECT, 2022
** RTypeMirror
** File description:
** GameScene
*/

#include "GameScene.hpp"

// #include "../ecs/enums/event.hpp"

#include "../ecs/systems/Fire.hpp"
#include "../ecs/systems/Input.hpp"

#include "../ecs/components/Clickable.hpp"
#include "../ecs/components/DrawableClientSide.hpp"
#include "../ecs/components/HitBox.hpp"
#include "../ecs/components/Position.hpp"
#include "../ecs/components/Text.hpp"

#include "../ecs/systems/Click.hpp"
#include "../ecs/systems/Display.hpp"

using namespace rtype;
using namespace ecs;

GameScene::GameScene(std::shared_ptr<SceneSystem> sceneSystem, sf::RenderWindow &window, sf::Event &event,
    const std::string &sceneName, const float scale, std::shared_ptr<Communicator> communicator, boost::thread *thread)
    : AScene(sceneSystem, window, sceneName, scale, communicator, thread), _event(event)
{
}

GameScene::~GameScene() {}

void GameScene::OnCreate() { _sceneSystem->getEcs()->createEntityManager(this->getName()); }

void GameScene::OnDestroy() {}

void GameScene::OnActivate() { _sceneSystem->getTextureDatabase()->onCall(this->getName()); }

void GameScene::OnDeactivate() {}

void GameScene::ProcessInput() {}

void GameScene::Update()
{
    _communicator->lockSendMutex();
    // _communicator->_sendStream.str(std::string());
    _communicator->_sendStream << "action%" << this->_id << " ";
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        _communicator->_sendStream << "_up ";
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        _communicator->_sendStream << "_left ";
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        _communicator->_sendStream << "_down ";
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        _communicator->_sendStream << "_right ";
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        _communicator->_sendStream << "_fire ";
    _communicator->unlockSendMutex();

    return;
}

void GameScene::createEntity(std::string data, size_t entityId)
{
    // special case type
    auto &entity = _sceneSystem->getEcs()->getEntityManager(this->getName()).createEntity(entityId);

    // setType
    std::string type = data.substr(0, data.find(':'));
    entity.addComponent<DrawableClientSide>(_sceneSystem->getTextureDatabase()->getTexture(type), _scale);
    data.erase(0, data.find(':') + 1);

    // setPostion
    std::string positions = data.substr(0, data.find(':'));
    std::string positionX = positions.substr(0, data.find(','));
    std::string positionY = positions.substr(data.find(',') + 1, positions.size());
    entity.addComponent<Position>(stoi(positionX) * _scale, stoi(positionY) * _scale);
    data.erase(0, data.find(':') + 1);
}

void GameScene::updateEntity(ecs::Entity &entity, std::string data)
{
    //  special case type
    if (data == "delete") {
        _sceneSystem->getEcs()->getEntityManager(this->getName()).removeEntity(entity.getId());
        return;
    }
    // setType
    data.erase(0, data.find(':') + 1);

    // setPostion
    std::string positions = data.substr(0, data.find(':'));
    std::string positionX = positions.substr(0, data.find(','));
    std::string positionY = positions.substr(data.find(',') + 1, positions.size());
    entity.getComponent<Position>().setPosition(stoi(positionX) * _scale, stoi(positionY) * _scale);
    data.erase(0, data.find(':') + 1);
}

void GameScene::Draw()
{
    // receive packet
    std::string receivedData(_sceneSystem->getReceivedData());
    receivedData.erase(0, receivedData.find('%') + 3);

    while (receivedData.size() > 0) {
        std::string token = receivedData.substr(0, receivedData.find(' '));
        if (_sceneSystem->getEcs()->getEntityManager(this->getName()).getEntities().contains(token[0] - 48))
            updateEntity(_sceneSystem->getEcs()->getEntityManager(this->getName()).getEntity(token[0] - 48),
                token.substr(2, token.size()));
        else
            createEntity(token.substr(2, token.size()), token[0] - 48);
        receivedData.erase(0, receivedData.find(' ') + 1);
    }
    _sceneSystem->getEcs()->getSystem<Display>().run(_sceneName, _window);
}
