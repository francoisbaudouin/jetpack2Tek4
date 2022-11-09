/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Hub
*/

#include "Hub.hpp"
#include <SFML/Graphics/Text.hpp>

#include "../ecs/components/DrawableClientSide.hpp"
#include "../ecs/components/HitBox.hpp"
#include "../ecs/components/Position.hpp"
#include "../ecs/components/TextBox.hpp"

#include "../ecs/systems/Display.hpp"
#include "../ecs/systems/WriteInBox.hpp"

using namespace ecs;
using namespace rtype;

Hub::Hub(SceneSystem &sceneSystem, sf::RenderWindow &window, sf::Event &event, const std::string &sceneName)
    : AScene(sceneSystem, window, sceneName), _event(event)
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
}

void Hub::OnDestroy() {}

void Hub::OnActivate()
{
    /* wa are going to create different entity here (with they're components),
    dont forget to init the textureDatabase of the corresponding scene */
    _sceneSystem.getTextureDatabase()->onCall(this->getName());
    auto &ecs = _sceneSystem.getEcs();
    auto &hereManager = _sceneSystem.getEcs()->getEntityManager(this->getName());

    auto &ipPlaceholder = hereManager.getEntity(_entityGenerator.createEntity(hereManager, "Placeholder"));
    auto &portPlaceholder = hereManager.getEntity(_entityGenerator.createEntity(hereManager, "Placeholder"));
    auto &hube = hereManager.getEntity(_entityGenerator.createEntity(hereManager, "Default"));

    hube.addComponent<DrawableClientSide>(_sceneSystem.getTextureDatabase()->getTexture("HubForm"));
    ipPlaceholder.addComponent<DrawableClientSide>(_sceneSystem.getTextureDatabase()->getTexture("PlaceHolder"));
    portPlaceholder.addComponent<DrawableClientSide>(_sceneSystem.getTextureDatabase()->getTexture("PlaceHolder"));

    hube.getComponent<Position>().setPosition(100, 100);

    ipPlaceholder.getComponent<HitBox>().setHitBox(100, 20);
    ipPlaceholder.getComponent<TextBox>().setFontSize(10);
    ipPlaceholder.getComponent<Position>().setPosition(
        hube.getComponent<Position>().getX() + 25, hube.getComponent<Position>().getY() + 10);

    portPlaceholder.getComponent<HitBox>().setHitBox(100, 20);
    portPlaceholder.getComponent<TextBox>().setFontSize(10);
    portPlaceholder.getComponent<Position>().setPosition(
        hube.getComponent<Position>().getX() + 25, hube.getComponent<Position>().getY() + 35);
}

void Hub::OnDeactivate() {}

void Hub::ProcessInput() {}

void Hub::Update() { _sceneSystem.getEcs()->getSystem<WriteInBox>().run(_sceneName, _event, _window); }

void Hub::Draw() { _sceneSystem.getEcs()->getSystem<Display>().run(_sceneName, _window); }