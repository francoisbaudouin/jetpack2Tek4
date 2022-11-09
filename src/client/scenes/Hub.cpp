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
    float scale = 4;
    _sceneSystem.getTextureDatabase()->onCall(this->getName());
    auto &textBox = _sceneSystem.getEcs()->getEntityManager(this->getName()).createEntity();
    auto &hube = _sceneSystem.getEcs()->getEntityManager(this->getName()).createEntity();
    hube.addComponent<Position>(25, 25);
    hube.addComponent<DrawableClientSide>(_sceneSystem.getTextureDatabase()->getTexture("HubForm"), scale);
    textBox.addComponent<Position>(hube.getComponent<Position>().getX() + 25 * scale, hube.getComponent<Position>().getY() + 25 * scale);
    textBox.addComponent<HitBox>(100 * scale, 20 * scale);
    textBox.addComponent<TextBox>();
    textBox.getComponent<TextBox>().setFont("assets/Boxy-Bold.ttf");
    textBox.getComponent<TextBox>().setFontSize(15 * scale);
    textBox.addComponent<DrawableClientSide>(_sceneSystem.getTextureDatabase()->getTexture("PlaceHolder"), scale);
}

void Hub::OnDeactivate() {}

void Hub::ProcessInput() {}

void Hub::Update() { _sceneSystem.getEcs()->getSystem<WriteInBox>().run(_sceneName, _event, _window); }

void Hub::Draw() { _sceneSystem.getEcs()->getSystem<Display>().run(_sceneName, _window); }