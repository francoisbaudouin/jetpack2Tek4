/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Lobby
*/

#include "Lobby.hpp"

#include "../ecs/components/DrawableClientSide.hpp"
#include "../ecs/components/Position.hpp"

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

    auto &player = hereManager.createEntity();
    player.addComponent<DrawableClientSide>(_sceneSystem.getTextureDatabase()->getTexture("Player"), _scale);
    player.addComponent<Position>(0 * _scale, 0 * _scale);
}

void Lobby::OnDeactivate() {}

void Lobby::ProcessInput() {}

void Lobby::Update() {}

void Lobby::createEntity(std::string data, size_t entityId)
{
    // special case type
    auto &entity = _sceneSystem.getEcs()->getEntityManager(this->getName()).createEntity();
    entity.setId(entityId);

    // setType
    std::string type = data.substr(0, data.find(':'));
    entity.addComponent<DrawableClientSide>(_sceneSystem.getTextureDatabase()->getTexture(type), _scale);
    data.erase(0, data.find(':') + 1);

    // setPostion
    std::string positions = data.substr(0, data.find(':'));
    std::string positionX = positions.substr(0, data.find(','));
    std::string positionY = positions.substr(data.find(',') + 1, positions.size());
    entity.addComponent<Position>(stoi(positionX) * _scale, stoi(positionY) * _scale);
    data.erase(0, data.find(':') + 1);
}

void Lobby::updateEntity(ecs::Entity &entity, std::string data)
{
    size_t scale = entity.getComponent<DrawableClientSide>().getScale().x;
    // special case type
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
    entity.getComponent<Position>().setPosition(stoi(positionX) * scale, stoi(positionY) * scale);
    data.erase(0, data.find(':') + 1);
}

void Lobby::Draw()
{
    // receive packet
    std::string receivedData(_communicator->_receiveStream.str());
    receivedData.erase(0, this->getName().size() + 1);

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