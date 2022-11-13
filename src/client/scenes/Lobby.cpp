/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Lobby
*/

#include "Lobby.hpp"

#include "../ecs/components/Clickable.hpp"
#include "../ecs/components/DrawableClientSide.hpp"
#include "../ecs/components/HitBox.hpp"
#include "../ecs/components/Position.hpp"
#include "../ecs/components/Text.hpp"

#include "../ecs/systems/Click.hpp"
#include "../ecs/systems/Display.hpp"

using namespace rtype;
using namespace ecs;

Lobby::Lobby(SceneSystem &sceneSystem, sf::RenderWindow &window, sf::Event &event, const std::string &sceneName,
    const float scale, std::shared_ptr<Communicator> communicator, boost::thread *thread)
    : AScene(sceneSystem, window, sceneName, scale, communicator, thread), _event(event)
{
}

Lobby::~Lobby() {}

void Lobby::OnCreate()
{
    /* We are going to create system here,
    dont forget to create the corresponding entityManager */
    _sceneSystem.getEcs()->createEntityManager(this->getName());
}

void Lobby::OnDestroy() {}

void Lobby::OnActivate()
{
    /* wa are going to create different entity here (with they're components),
    dont forget to init the textureDatabase of the corresponding scene */
    _sceneSystem.getTextureDatabase()->onCall(this->getName());
    auto &hereManager = _sceneSystem.getEcs()->getEntityManager(this->getName());

    auto &readyButton = hereManager.getEntity(generateEntity(hereManager, "Button", 5));
    readyButton.getComponent<HitBox>().setHitBox(100 * _scale, 20 * _scale);
    readyButton.getComponent<Text>().setText(std::string("CONFIRM"));
    readyButton.getComponent<Text>().setFontSize(10 * _scale);
    readyButton.getComponent<Position>().setPosition(100, 100);
}
void Lobby::OnDeactivate() {}

void Lobby::ProcessInput() {}

void Lobby::Update()
{
    _sceneSystem.getEcs()->getSystem<Click>().run(_sceneName, _window);
    if (_sceneSystem.getEcs()->getEntityManager(this->getName()).getEntity(5).getComponent<Clickable>().isClicked()) {
        _communicator->lockSendMutex();
        _communicator->_sendStream.str(std::string());
        _communicator->_sendStream << "ready ";
        _communicator->unlockSendMutex();
    }
    if (_sceneSystem.getEcs()->getEntityManager(this->getName()).getEntity(5).getComponent<Clickable>().isHovered()) {
        _sceneSystem.getEcs()
            ->getEntityManager(this->getName())
            .getEntity(5)
            .getComponent<Text>()
            .setColor(sf::Color::Red);
    } else {
        _sceneSystem.getEcs()
            ->getEntityManager(this->getName())
            .getEntity(5)
            .getComponent<Text>()
            .setColor(sf::Color::White);
    }
}

void Lobby::createEntity(std::string data, size_t entityId)
{
    // special case type
    auto &entity = _sceneSystem.getEcs()->getEntityManager(this->getName()).createEntity(entityId);

    // setType
    std::string type = data.substr(0, data.find(':'));
    entity.addComponent<DrawableClientSide>(_sceneSystem.getTextureDatabase()->getTexture(type), _scale);
    data.erase(0, data.find(':') + 1);

    // setPostion
    std::string positions = data.substr(0, data.find(':'));
    std::string positionX = positions.substr(0, data.find(','));
    std::string positionY = positions.substr(data.find(',') + 1, positions.size());
    entity.addComponent<Position>(stof(positionX) * _scale, stof(positionY) * _scale);
    data.erase(0, data.find(':') + 1);
}

void Lobby::updateEntity(ecs::Entity &entity, std::string data)
{
    //  special case type
    if (data == "delete") {
        _sceneSystem.getEcs()->getEntityManager(this->getName()).removeEntity(entity.getId());
        return;
    }
    // setType
    data.erase(0, data.find(':') + 1);

    // setPostion
    std::string positions = data.substr(0, data.find(':'));
    std::string positionX = positions.substr(0, data.find(','));
    std::string positionY = positions.substr(data.find(',') + 1, positions.size());
    entity.getComponent<Position>().setPosition(stof(positionX) * _scale, stof(positionY) * _scale);
    data.erase(0, data.find(':') + 1);
}

void Lobby::Draw()
{
    // receive packet
    std::string receivedData(_sceneSystem.getReceivedData());
    receivedData.erase(0, receivedData.find('%') + 3);

    while (receivedData.size() > 0) {
        std::string token = receivedData.substr(0, receivedData.find(' '));
        if (_sceneSystem.getEcs()->getEntityManager(this->getName()).getEntities().contains(token[0] - 48))
            updateEntity(_sceneSystem.getEcs()->getEntityManager(this->getName()).getEntity(token[0] - 48),
                token.substr(2, token.size()));
        else
            createEntity(token.substr(2, token.size()), token[0] - 48);
        receivedData.erase(0, receivedData.find(' ') + 1);
    }
    _sceneSystem.getEcs()->getSystem<Display>().run(_sceneName, _window);
}