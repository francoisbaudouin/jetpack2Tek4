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
#include "../ecs/components/Selectable.hpp"


#include "../ecs/systems/Animate.hpp"
#include "../ecs/systems/Click.hpp"
#include "../ecs/systems/Display.hpp"
#include "../ecs/systems/Fire.hpp"
#include "../ecs/systems/Input.hpp"
#include "../ecs/systems/WriteInBox.hpp"

using namespace ecs;
using namespace rtype;

Hub::Hub(std::shared_ptr<SceneSystem> sceneSystem, sf::RenderWindow &window, sf::Event &event,
    const std::string &sceneName, const float scale, std::shared_ptr<Communicator> communicator, boost::thread *thread)
    : AScene(sceneSystem, window, sceneName, scale, communicator, thread), _event(event)
{
}

Hub::~Hub() {}

void Hub::OnCreate()
{
    /* We are going to create system here,
    dont forget to create the corresponding entityManager */
    _sceneSystem->getEcs()->createEntityManager(this->getName());

    auto &hereManager = _sceneSystem->getEcs()->getEntityManager(this->getName());

    _sceneSystem->getTextureDatabase()->onCall(this->getName());

    auto &background = hereManager.getEntity(ecs::generateEntity(hereManager, "Default"));
    auto &ipPlaceholder = hereManager.getEntity(ecs::generateEntity(hereManager, "Placeholder"));
    auto &ipText = hereManager.getEntity(ecs::generateEntity(hereManager, "Default"));
    auto &portPlaceholder = hereManager.getEntity(ecs::generateEntity(hereManager, "Placeholder"));
    auto &portText = hereManager.getEntity(ecs::generateEntity(hereManager, "Default"));
    auto &backButton = hereManager.getEntity(ecs::generateEntity(hereManager, "Button"));
    auto &confirmButton = hereManager.getEntity(ecs::generateEntity(hereManager, "Button"));

    background.addComponent<DrawableClientSide>(
        _sceneSystem->getTextureDatabase()->getTexture("Background"), _scale * 2);

    ipText.addComponent<Text>();
    ipText.getComponent<Position>().setPosition(
        _window.getSize().x / 3 - (70 * _scale), _window.getSize().y / 3 - (15 * _scale));
    ipText.getComponent<Text>().setText(std::string("IP:________________"));
    ipText.getComponent<Text>().setFontSize(30 * _scale);
    ipText.addComponent<Clickable>();
    ipText.addComponent<Selectable>();
    ipText.addComponent<HitBox>(
        ipText.getComponent<Text>().getTextWidth(), ipText.getComponent<Text>().getTextHeight() * _scale);


    portText.addComponent<Text>();
    portText.getComponent<Text>().setFontSize(30 * _scale);

    portText.getComponent<Position>().setPosition(ipText.getComponent<Position>().getX(),
        ipText.getComponent<Position>().getY() + (2 * ipText.getComponent<Text>().getFontSize()));
    portText.getComponent<Text>().setText(std::string("PORT:______________"));
    portText.addComponent<Clickable>();
    portText.addComponent<Selectable>();
    portText.addComponent<HitBox>(
        portText.getComponent<Text>().getTextWidth(), portText.getComponent<Text>().getTextHeight() * _scale);


    ipPlaceholder.getComponent<Text>().setText(std::string(""));
    ipPlaceholder.getComponent<Text>().setFontSize(30 * _scale);
    ipPlaceholder.getComponent<Position>().setPosition(
        ipText.getComponent<Position>().getX() + (60 * _scale), ipText.getComponent<Position>().getY() - (10 * _scale));
    ipPlaceholder.getComponent<TextBox>().setMaxLenght(20);
    ipPlaceholder.getComponent<HitBox>().setHitBox(
        ipText.getComponent<Text>().getTextWidth(), ipText.getComponent<Text>().getTextHeight() * _scale);


    portPlaceholder.getComponent<Text>().setText(std::string(""));
    portPlaceholder.getComponent<Text>().setFontSize(30 * _scale);
    portPlaceholder.getComponent<Position>().setPosition(portText.getComponent<Position>().getX() + (90 * _scale),
        portText.getComponent<Position>().getY() - (10 * _scale));
    portPlaceholder.getComponent<TextBox>().setMaxLenght(20);
    portPlaceholder.getComponent<HitBox>().setHitBox(
        portText.getComponent<Text>().getTextWidth(), portText.getComponent<Text>().getTextHeight() * _scale);

    backButton.getComponent<Text>().setText(std::string("BACK"));
    backButton.getComponent<Text>().setFontSize(20 * _scale);
    backButton.getComponent<HitBox>().setHitBox(
        backButton.getComponent<Text>().getTextWidth(), backButton.getComponent<Text>().getTextHeight() * _scale);
    backButton.getComponent<Position>().setPosition(
        portText.getComponent<Position>().getX(), portText.getComponent<Position>().getY() + (60 * _scale));

    confirmButton.getComponent<Text>().setText(std::string("CONFIRM"));
    confirmButton.getComponent<Text>().setFontSize(20 * _scale);
    confirmButton.getComponent<HitBox>().setHitBox(
        confirmButton.getComponent<Text>().getTextWidth(), confirmButton.getComponent<Text>().getTextHeight() * _scale);
    confirmButton.getComponent<Position>().setPosition(
        backButton.getComponent<Position>().getX() + (250 * _scale), backButton.getComponent<Position>().getY());
}

void Hub::OnDestroy() {}

void Hub::OnActivate() { _sceneSystem->getTextureDatabase()->onCall(this->getName()); }

void Hub::OnDeactivate() {}

void Hub::ProcessInput() {}

void Hub::Update()
{
    if (_sceneSystem->getEcs()->getEntityManager(this->getName()).getEntity(5).getComponent<Clickable>().isClicked()) {
        _sceneSystem->SwitchTo("MainMenu");
    } else if (_sceneSystem->getEcs()
                   ->getEntityManager(this->getName())
                   .getEntity(6)
                   .getComponent<Clickable>()
                   .isClicked()) {
        _ipServer = _sceneSystem->getEcs()
                        ->getEntityManager(this->getName())
                        .getEntity(1)
                        .getComponent<TextBox>()
                        .getReferenceString();
        _portServer = _sceneSystem->getEcs()
                          ->getEntityManager(this->getName())
                          .getEntity(3)
                          .getComponent<TextBox>()
                          .getReferenceString();
        _communicator->setIpAdress(_ipServer);
        _communicator->setPort(stoi(_portServer));
        _communicator->startCommunication();

        _communicator->lockSendMutex();
        _communicator->_sendStream << "connect ";
        _communicator->unlockSendMutex();
    }
    _sceneSystem->getEcs()->getSystem<WriteInBox>().run(this->getName(), _event);
    _sceneSystem->getEcs()->getSystem<Click>().run(this->getName(), _window);
}

void Hub::Draw()
{
    // receive packet
    _sceneSystem->getEcs()->getSystem<Animate>().runButton(this->getName());
    _sceneSystem->getEcs()->getSystem<Animate>().runSelectable(this->getName());
    _sceneSystem->getEcs()->getSystem<Display>().run(this->getName(), _window);
}
