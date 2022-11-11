/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Hub
*/

#include "Hub.hpp"
#include <SFML/Graphics/Text.hpp>
#include <string>

#include "../ecs/components/DrawableClientSide.hpp"
#include "../ecs/components/HitBox.hpp"
#include "../ecs/components/Position.hpp"
#include "../ecs/components/Text.hpp"
#include "../ecs/components/TextBox.hpp"

#include "../ecs/systems/Click.hpp"
#include "../ecs/systems/Display.hpp"
#include "../ecs/systems/WriteInBox.hpp"

using namespace ecs;
using namespace rtype;

Hub::Hub(SceneSystem &sceneSystem, sf::RenderWindow &window, sf::Event &event, const std::string &sceneName,
    const float scale, std::shared_ptr<Communicator> communicator)
    : AScene(sceneSystem, window, sceneName, scale, communicator), _event(event)
{
}

Hub::~Hub() {}

void Hub::OnCreate()
{
    /* We are going to create system here,
    dont forget to create the corresponding entityManager */
    _sceneSystem.getEcs()->createEntityManager(this->getName());
    _sceneSystem.getEcs()->createSystem<WriteInBox>(_sceneSystem.getEcs());
    _sceneSystem.getEcs()->createSystem<Display>(_sceneSystem.getEcs());
    _sceneSystem.getEcs()->createSystem<Click>(_sceneSystem.getEcs());
}

void Hub::OnDestroy() {}

void Hub::OnActivate()
{
    /* wa are going to create different entity here (with they're components),
    dont forget to init the textureDatabase of the corresponding scene */
    _sceneSystem.getTextureDatabase()->onCall(this->getName());
    auto &hereManager = _sceneSystem.getEcs()->getEntityManager(this->getName());

    auto &ipPlaceholder = hereManager.getEntity(_entityGenerator.createEntity(hereManager, "Placeholder"));
    auto &portPlaceholder = hereManager.getEntity(_entityGenerator.createEntity(hereManager, "Placeholder"));
    auto &confirmButton = hereManager.getEntity(_entityGenerator.createEntity(hereManager, "Button"));
    auto &hube = hereManager.getEntity(_entityGenerator.createEntity(hereManager, "Default"));

    hube.addComponent<DrawableClientSide>(_sceneSystem.getTextureDatabase()->getTexture("HubForm"), _scale);
    ipPlaceholder.addComponent<DrawableClientSide>(
        _sceneSystem.getTextureDatabase()->getTexture("PlaceHolder"), _scale);
    portPlaceholder.addComponent<DrawableClientSide>(
        _sceneSystem.getTextureDatabase()->getTexture("PlaceHolder"), _scale);

    hube.getComponent<Position>().setPosition(100 * _scale, 100 * _scale);

    ipPlaceholder.getComponent<HitBox>().setHitBox(100 * _scale, 20 * _scale);
    ipPlaceholder.getComponent<Text>().setFontSize(10 * _scale);
    ipPlaceholder.getComponent<Position>().setPosition(
        hube.getComponent<Position>().getX() + (25 * _scale), hube.getComponent<Position>().getY() + (10 * _scale));

    portPlaceholder.getComponent<HitBox>().setHitBox(100 * _scale, 20 * _scale);
    portPlaceholder.getComponent<Text>().setFontSize(10 * _scale);
    portPlaceholder.getComponent<Position>().setPosition(
        hube.getComponent<Position>().getX() + (25 * _scale), hube.getComponent<Position>().getY() + (35 * _scale));

    confirmButton.getComponent<HitBox>().setHitBox(100 * _scale, 20 * _scale);
    confirmButton.getComponent<Text>().setText(std::string("CONFIRM"));
    confirmButton.getComponent<Text>().setFontSize(10 * _scale);
    confirmButton.getComponent<Position>().setPosition(
        hube.getComponent<Position>().getX() + (40 * _scale), hube.getComponent<Position>().getY() + (60 * _scale));
}

void Hub::OnDeactivate() {}

void Hub::ProcessInput() {}

void Hub::Update()
{
    _sceneSystem.getEcs()->getSystem<WriteInBox>().run(_sceneName, _event);
    _sceneSystem.getEcs()->getSystem<Click>().run(_sceneName, _window);
    if (_sceneSystem.getEcs()->getEntityManager(this->getName()).getEntity(2).getComponent<Clickable>().isClicked()) {
        _ipServer = _sceneSystem.getEcs()
                        ->getEntityManager(this->getName())
                        .getEntity(0)
                        .getComponent<TextBox>()
                        .getReferenceString();
        _portServer = _sceneSystem.getEcs()
                          ->getEntityManager(this->getName())
                          .getEntity(1)
                          .getComponent<TextBox>()
                          .getReferenceString();
        _communicator->setIpAdress(_ipServer);
        _communicator->setPort(stoi(_portServer));
        _thread = std::make_shared<boost::thread>(boost::thread(boost::bind(&rtype::Communicator::connectToServer, _communicator)));
        //while (1)
    }


    if (_sceneSystem.getEcs()->getEntityManager(this->getName()).getEntity(2).getComponent<Clickable>().isHovered()) {
        _sceneSystem.getEcs()
            ->getEntityManager(this->getName())
            .getEntity(2)
            .getComponent<Text>()
            .setColor(sf::Color::Red);
    } else {
        _sceneSystem.getEcs()
            ->getEntityManager(this->getName())
            .getEntity(2)
            .getComponent<Text>()
            .setColor(sf::Color::Black);
    }
}

void Hub::Draw()
{
    // receive packet
    _sceneSystem.getEcs()->getSystem<Display>().run(_sceneName, _window);
}